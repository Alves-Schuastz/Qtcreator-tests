#include <QCoreApplication>

#include <QDebug>

#include <memory>

class Product {
public:
    Product( const int idProduct, const QString& dsProduct ) :
        _idProduct( idProduct ),
        _dsProduct( dsProduct ) {}

    ~Product() {
        qInfo() << "Product::~Product [ID_PRODUCT]" << _idProduct << "[DS_PRODUCT]" << _dsProduct;
    }

    int idProduct() const {
        return _idProduct;
    }

    void setIdProduct( int idProduct ) {
        _idProduct = idProduct;
    }

    QString dsProduct() const {
        return _dsProduct;
    }

    void setDsProduct( const QString& dsProduct ) {
        _dsProduct = dsProduct;
    }

private:
    int _idProduct;
    QString _dsProduct;
};

struct MyDeleter {
    void operator()( Product* ptr ) {
        qInfo() << "MyDeleter::operator deleting pointer";
        delete ptr;
    }
};

class ProductRepository {
public:
    Product* findById( const int idProduct ) const {
        return new Product( idProduct, "Qualquer coisa" );
    }
};

class ProductService {
public:
    void updateProduct( const int idProduct, const QString& dsProduct, Product* product ) const {
        product->setDsProduct( dsProduct );
        product->setIdProduct( idProduct );
    };

    Product* findById( const int idProduct ) const {
        return ProductRepository().findById( idProduct );
    }
};

class ProductController {
public:
    ProductController() :
        _product( nullptr ) {}
    ~ProductController() {
        qInfo() << "ProductController::~ProductController";
    };

    QString dsProductById( const int idProduct ) {
        _product.reset( ProductService().findById( idProduct ) );
        return _product->dsProduct();
    }
private:
    std::unique_ptr<Product> _product;
};

int main( int argc, char* argv[] ) {

    QCoreApplication a( argc, argv );

    {
        std::unique_ptr<Product> product ( new Product( 1, "Arroz" ) );
    }

    {
        std::unique_ptr<Product> product = std::make_unique<Product>( 2, "Suco de uva" ); // Método preferido ( C++ 14 em diante )
    }

    {
        std::unique_ptr<Product> product( new Product( 3, "Abacate" ) );

        std::unique_ptr<Product> product2 = std::move( product );  // A propriedade é transferida de product para product2

        if ( product ) {
            qInfo() << "Product possui o objeto";
        } else if ( product2 ) {
            qInfo() << "Product2 possui o objeto";
        }
    }

    {
        std::unique_ptr<Product, MyDeleter> product( new Product( 4, "Coca-cola" ), MyDeleter() );
    }

    {
        std::unique_ptr<Product, MyDeleter> product( new Product( 5, "Fanta" ), MyDeleter() );

        std::unique_ptr<Product, MyDeleter> product2 = std::move( product );  // A propriedade é transferida de product para product2

        if ( product ) {
            qInfo() << "Product possui o objeto";
        } else if ( product2 ) {
            qInfo() << "Product2 possui o objeto";
        }
    }

    {

        std::unique_ptr<Product> product( new Product( 6, "Café" ) );

        ProductService().updateProduct( 7, "Capuccino", product.get() );

    }

    {

        std::unique_ptr<Product> product( new Product( 6, "Café" ) );

        ProductService().updateProduct( 7, "Capuccino", product.get() );

        product->setDsProduct( "Fanta Limão" );

    }

    {

        std::unique_ptr<Product> product( new Product( 6, "Café" ) );

        ProductService().updateProduct( 7, "Capuccino", product.get() );

        Product* productPointer = product.release();

        if ( product ) {
            qInfo() << "Product possui o objeto";
        } else if ( productPointer ) {
            qInfo() << "ProductPointer possui o objeto";
        }

        delete productPointer;
        productPointer = nullptr;

    }

    {

        std::unique_ptr<Product> product( new Product( 6, "Café" ) );

        product.reset( new Product( 9, "Goiaba" ) );

    }

    {
        std::unique_ptr<Product> product1( new Product( 6, "Café" ) );
        std::unique_ptr<Product> product2( new Product( 7, "Despertador" ) );

        qInfo() << "[ENDERECO_PRODUTO1]" << &product1 << "[ENDERECO_POINTEIRO]" << product1.get() << "[ID_PRODUTO]" << product1->idProduct() << "[DS_PRODUTO]" << product1->dsProduct();
        qInfo() << "[ENDERECO_PRODUTO2]" << &product2 << "[ENDERECO_POINTEIRO]" << product2.get() << "[ID_PRODUTO]" << product2->idProduct() << "[DS_PRODUTO]" << product2->dsProduct();

        product1.swap( product2 );

        qInfo() << "[ENDERECO_PRODUTO1]" << &product1 << "[ENDERECO_POINTEIRO]" << product1.get() << "[ID_PRODUTO]" << product1->idProduct() << "[DS_PRODUTO]" << product1->dsProduct();
        qInfo() << "[ENDERECO_PRODUTO2]" << &product2 << "[ENDERECO_POINTEIRO]" << product2.get() << "[ID_PRODUTO]" << product2->idProduct() << "[DS_PRODUTO]" << product2->dsProduct();

    }

    {

        const QString dsProduct = ProductController().dsProductById( 1 );

        qInfo() << "[DS_PRODUTO]" << dsProduct;
    }

    {

        ProductController productController;

        const QString dsProduct = productController.dsProductById( 1 );

        qInfo() << "[DS_PRODUTO]" << dsProduct;

        const QString dsProduct2 = productController.dsProductById( 2 );

        qInfo() << "[DS_PRODUTO_2]" << dsProduct2;

    }

    {

        // Garante que o recurso que ele gerencia tem uma propriedade exclusiva.

        std::unique_ptr<Product> product( new Product( 6, "Café" ) );

        //  std::unique_ptr<Product> product2 = product;

    }

    return a.exec();
}
