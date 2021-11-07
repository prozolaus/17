#include "std_lib_facilities.h"

struct God
{
    string name;
    string country;
    string vehicle;
    string weapon;
};

class Link
{
public:
    God god;
    Link(const string &name, const string &country = "",
         const string &vehicle = "", const string &weapon = "", Link *p = nullptr, Link *s = nullptr)
        : prev{p}, succ{s}
    {
        god.name = name;
        god.country = country;
        god.vehicle = vehicle;
        god.weapon = weapon;
    }
    Link *insert(Link *n);
    Link *add(Link *n);
    Link *add_ordered(Link *n);
    Link *erase();
    Link *find(const string &s);
    const Link *find(const string &s) const;
    Link *advance(int n);
    Link *next() const { return succ; };
    Link *previous() const { return prev; };

private:
    Link *prev;
    Link *succ;
};

Link *Link::insert(Link *n)
{
    if (n == nullptr)
        return this;
    if (this == nullptr)
        return n;
    n->succ = this;
    if (prev)
        prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}

Link *Link::add(Link *n)
{
    if (n == nullptr)
        return this;
    if (this == nullptr)
        return n;
    n->prev = this;
    if (succ)
        succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

Link *Link::add_ordered(Link *n)
{
    if (n == nullptr)
        error("nullptr was sent to add_ordered()");

    Link *p = this;
    while (p)
        if (n->god.name > p->god.name)
        {
            if (p->succ == nullptr)
            {
                p->add(n);
                break;
            }
            else
                p = p->succ;
        }
        else
        {
            p->insert(n);
            break;
        }
    //set pointer "p" to the first position and return it
    while (p->prev)
        p = p->prev;

    return p;
}

Link *Link::erase()
{
    if (this == nullptr)
        return nullptr;
    if (succ)
        succ->prev = prev;
    if (prev)
        prev->succ = succ;
    return succ;
}

Link *Link::find(const string &s)
{
    Link *p = this;
    while (p)
    {
        if (p->god.name == s)
            return p;
        p = p->succ;
    }
    return nullptr;
}

Link *Link::advance(int n)
{
    Link *p = this;
    if (p == nullptr)
        return nullptr;
    if (0 < n)
        while (n--)
        {
            if (p->succ == nullptr)
                return nullptr;
            p = p->succ;
        }
    else if (n < 0)
        while (n++)
        {
            if (p->prev == nullptr)
                return nullptr;
            p = p->prev;
        }
    return p;
}

void print_all(Link *p)
{
    while (p)
    {
        cout << "Имя: "<< p->god.name << ".\nМесто: " << p->god.country 
            << ".\nТранспортное средство: " << p->god.vehicle << ".\nОружие: " << p->god.weapon << ".";
        if (p = p->next())
            cout << "\n\n";
    }
    cout << "\n\n-------------------------------------------\n\n";
}

int main()
try
{
    Link *norse_gods = new Link{"Тор", "Асгард", "Летающая колесница", "Молот Мьёльнир"};
    norse_gods = norse_gods->add_ordered(new Link{"Хеймдалль", "Химинбьёрг", "Лошадь с золотой гривой - Гулльтоп", "Золотой рог - Гьяллархорн"});
    norse_gods = norse_gods->add_ordered(new Link{"Фрейр", "Асгард, Уппсала", "Корабль - Скидбладнир", "Меч света"});
    norse_gods = norse_gods->add_ordered(new Link{"Локи", "Ётунхейм", "Превращение в любое животное/существо/человека", "Изменение формы объекта"});
    norse_gods = norse_gods->add_ordered(new Link{"Улль", "Тисовая долина - Идалир", "Лыжи, сани", "Лук, меч"});

    Link *greek_gods = new Link{"Афина", "Аттика", "Колесница", "Копьё"};
    greek_gods = greek_gods->add_ordered(new Link{"Посейдон", "Дно моря", "Колесница", "Трезубец"});
    greek_gods = greek_gods->add_ordered(new Link{"Зевс", "Олимп", "Колесница", "Молния"});
    greek_gods = greek_gods->add_ordered(new Link{"Аполлон", "Олимп, Делос", "Колесница", "Лук, стрелы"});
    greek_gods = greek_gods->add_ordered(new Link{"Гера", "Аргос, Олимп", "Колесница", "Диадема"});

    Link *veda_gods = new Link{"Сурья", "Небеса", "Золотая колесница", "Изливание света и сияния"};
    veda_gods = veda_gods->add_ordered(new Link{"Варуна", "Мировые воды", "Морское чудовище - Макара", "Аркан (петля) из змеи"});
    veda_gods = veda_gods->add_ordered(new Link{"Брихаспати", "Планета Юпитер", "Колесница Закона", "Дубина грома, лук, стрелы, золотой топор"});
    veda_gods = veda_gods->add_ordered(new Link{"Вишну", "Океан космоса во Вселенной", "Птица - Гаруда", "Булава"});
    veda_gods = veda_gods->add_ordered(new Link{"Индра", "Небесное царство (рай) - Сварга", "Белый небесный слон - Айравата", "Копьё"});

    print_all(norse_gods);
    print_all(greek_gods);
    print_all(veda_gods);
}
catch (const std::exception &e)
{
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Some kind of exception\n";
    return 2;
}
