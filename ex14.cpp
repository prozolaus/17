#include "std_lib_facilities.h"

class Link
{
public:
    string value;
    Link(const string &v, Link *s = nullptr)
        : value{v}, succ{s} {}
    Link *insert(Link *n);
    Link *add(Link *n);
    Link *erase();
    Link *find(const string &s);
    const Link *find(const string &s) const;
    Link *advance(int n);
    Link *next() const { return succ; };

private:
    Link *succ;
};

Link *Link::insert(Link *n)
{
    if (n == nullptr)
        return this;
    if (this == nullptr)
        return n;
    n->succ = this;
    return n;
}

Link *Link::add(Link *n)
{
    if (n == nullptr)
        return this;
    if (this == nullptr)
        return n;
    succ = n;
    return n;
}

Link *Link::erase()
{
    if (this == nullptr)
        return nullptr;
    value = "";
    return succ;
}

Link *Link::find(const string &s)
{
    Link *p = this;
    while (p)
    {
        if (p->value == s)
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
        error("Negative argument in advance()");
    return p;
}

void print_all(Link *p)
{
    cout << "{ ";
    while (p)
    {
        cout << p->value;
        if (p = p->next())
            if (p->value != "") 
                cout << ", ";
    }
    cout << " }\n";
}

int main()
try
{
    Link *norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link *greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    Link *p = greek_gods->find("Mars");
    if (p)
        p->value = "Ares";

    Link *p2 = norse_gods->find("Zeus");
    if (p2)
    {
        if (p2 == norse_gods)
            norse_gods = p2->next();
        greek_gods = greek_gods->insert(new Link{p2->value});
        p2->erase();
    }

    Link *p3 = greek_gods->find("Hera");
    if (p3)
        p3->add(new Link{"Gefest"});

    print_all(norse_gods);
    print_all(greek_gods);
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
