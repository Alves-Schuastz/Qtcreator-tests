#include <QCoreApplication>

#include <QDebug>

class MyClass {
public:
    MyClass() {
        qInfo() << "MyClass::MyClass o construtor foi chamado";
    }
    ~MyClass() {
        qInfo() << "MyClass::~MyClass O destruidor foi chamado";
    }
};

class Document {
public:
    Document( const QString& name ) :
        _name( name ),
        _content( "" ) {
        qInfo() << "Document::Document [NOME]" << _name << "criado";
    }

    ~Document() {
        qInfo() << "Document::~Document [NOME]" << _name << "destruído";
    }

    void appendContent( const QString& content ) {
        _content += content;
    }

    void printContent() const {
        qInfo() << "Document::printContent conteúdo do documento [NOME]" << _name << "[CONTEUDO]" << _content;
    }

private:
    QString _name;
    QString _content;
};

class User {
public:
    User ( const QString& name ) :
        _name( name ) {}

    ~User() {
        qInfo() << "User::~User [NOME]" << _name << "destruído";
    }

    void accessDocument( const std::shared_ptr<Document>& document ) {
        qInfo() << "User::accessDocument [NOME]" << _name << "está acessando o documento.";
        _document = document;
    }

    void modifyDocument( const QString& content ) {

        if ( _document ) {
            _document->appendContent( content );
            qInfo() << "User::modifyDocument [NOME]" << _name << "modificou o documento.";
            return;
        }

        qInfo() << "User::modifyDocument [NOME]" << _name << "não tem acesso a nenhum documento.";

    }

    void showDocument() const {

        if ( _document ) {
            _document->printContent();
            return;
        }

        qInfo() << "User::showDocument [NOME]" << _name << "não tem acesso a nenhum documento.";

    }

private:
    QString _name;
    std::shared_ptr<Document> _document;
};

int main( int argc, char* argv[] ) {
    QCoreApplication a( argc, argv );

    {
        std::shared_ptr<MyClass> ptr1( new MyClass() );

        {

            qInfo() << "Dentro do escopo interno [REFERENCIAS_AO_PONTEIRO]" << ptr1.use_count();

            std::shared_ptr<MyClass> ptr2 = ptr1;

            qInfo() << "Dentro do escopo interno [REFERENCIAS_AO_PONTEIRO]" << ptr1.use_count() << "[UNICO]" << ptr1.unique();

            // Ambos os ponteiros compartilham o mesmo objeto e o contador de referência foi aumentado para 2
        }

        qInfo() << "Fora do escopo interno [REFERENCIAS_AO_PONTEIRO]" << ptr1.use_count() << "[UNICO]" << ptr1.unique();

        // Ao sair do escopo interno destruirá o ptr2 e o contador de referência será decrementado para 1

        // Ptr1 sai do escopo e o contador de referência torna-se 0
        // Isso faz com que o objeto MyClass seja excluído e o destruidor seja chamado
    }

    {
        std::shared_ptr<Document> document = std::make_shared<Document>( "Projeto X" );

        User alice( "Alice" );
        User bob( "Bob" );

        alice.accessDocument( document );
        bob.accessDocument( document );

        qInfo() << "Numero de referências ao ponteiro [REFERENCIAS]" << document.use_count();

        alice.modifyDocument( "Adicionando conteúdo pela Alice.\n" );
        bob.modifyDocument( "Adicionando conteúdo pelo Bob.\n" );

        alice.showDocument();
        bob.showDocument();

        {
            User joao( "Joao" );
            joao.accessDocument( document );
            joao.modifyDocument( "Adicionando conteúdo pelo Joao.\n" );
            joao.showDocument();
        }

        alice.showDocument();
    }

    return a.exec();
}
