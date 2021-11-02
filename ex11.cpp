#include "std_lib_facilities.h"

class Link
{
public:
    string value;
    Link(const string &v, Link *p = nullptr, Link *s = nullptr)
        : value{v}, prev{p}, succ{s} {}
    Link *insert(Link *n);
    Link *add(Link *n);
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
        while (n++)
        {
            if (p->prev == nullptr)
                return nullptr;
            p = p->prev;
        }
    return p;
}

int main()
try
{
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
