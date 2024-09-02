#ifndef TEMPLATELISTCONTROL_H
#define TEMPLATELISTCONTROL_H

#include <QObject>
#include <QList>

class TemplateListControl : public QObject {
    Q_OBJECT
    Q_PROPERTY( QList<int> inteiros READ inteiros WRITE setInteiros NOTIFY inteirosChanged CONSTANT )
    Q_PROPERTY( QList<QString> textos READ textos WRITE setTextos NOTIFY textosChanged CONSTANT )
    Q_PROPERTY( QList<double> decimais READ decimais WRITE setDecimais CONSTANT )
public:
    explicit TemplateListControl( QObject* parent = nullptr );

    QList<int> inteiros() const;
    void setInteiros( const QList<int>& inteiros );

    QList<QString> textos() const;
    void setTextos( const QList<QString>& textos );

    QList<double> decimais() const;
    void setDecimais( const QList<double>& decimais );

    Q_INVOKABLE void ordenarValores();
    Q_INVOKABLE void carregarValoresIniciais();

    template<typename T>
    QList<T> ordenacao(QList<T> &item);

signals:
    void inteirosChanged();
    void textosChanged();
    void decimaisChanged();

private:
    QList<int> _inteiros;
    QList<QString> _textos;
    QList<double> _decimais;
};

#endif // TEMPLATELISTCONTROL_H
