#include "poly.hpp"

#include <sstream>
int ZERO =0;
const int& Poly::operator[](const int exp) const {
    if (this->begin()!=this->end())
    {
        for(const_iterator it = this->begin();it!=this->end();it++)
        {
        if(it->first==exp)
        {
            return it->second;
        }
        }
    }
    return ZERO;
}

int& Poly::operator [](const int exp)
{
    iterator i;
    for(i = begin();i!=end();i++)
    {
        if(i->first==exp)
        {
            return m_values[exp];
        }
    }
    m_values[exp]=0;
    return m_values[exp];
}

Poly& Poly::operator+=(Poly const& b) {

    for(auto i = b.begin();i!=b.end();i++)
    {
        m_values[i->first] += i->second;
    }
    return *this;
}

Poly& Poly::operator-=(Poly const& b) {
  for(auto i = b.begin();i!=b.end();i++)
    {
        m_values[i->first] -= i->second;
    }
    return *this;
}

std::istream& operator>>(std::istream& is, Poly& p) {
    std::string token;
    if (!(is >> token)) return is; // Couldn't extract the token?
    std::istringstream iss(token);
    Poly tmp; // A temporary in order to avoid modifying p if an error occurs
    bool fail = false;
    for (int m, exp; iss >> m; tmp[exp] += m) {
        if (iss.get() == 'x' && iss >> exp) continue; // All OK, add to tmp
        fail = true;
        break;
    }
    if (!iss.eof()) fail = true; // Fail if iss >> m failed due to garbage rather than EOF
    if (fail) is.clear((is.rdstate() & ~std::ios::goodbit) | std::ios::failbit); // Set iostate fail
    else p = tmp; // All OK, output the result
    return is;
}

std::ostream& operator<<(std::ostream& os, Poly const& p) {
    auto i= p.begin() ;
    os<<i->second<<'x'<<i->first;
    i++;
    while(i!=p.end())
    {
        if(i->second>0)
            os<<'+';
        os<<i->second<<'x'<<i->first;
        i++;
    }
    return os;
}

Poly operator+(Poly const& a, Poly const& b) {
    Poly c;
    for(auto i = a.begin();i!=a.end();i++)
    {
        c[i->first] = i->second;
    }
    c += b;
    return c;
}

Poly operator-(Poly const& a, Poly const& b) {
    Poly c;
    for(auto i = a.begin();i!=a.end();i++)
    {
        c[i->first] = i->second;
    }
    c -= b;
return c;
}

Poly operator-(Poly const& p) {
    Poly q;
    for(auto i=p.begin();i!=p.end();i++)
    {
        q[i->first] = -(i->second);
    }
    return q;
}


bool operator<(Poly const& a, Poly const& b) {
    auto i = a.begin();
    auto j = b.begin();
    if(i->first<j->first)
        return true;
    else
        return false;
}

bool operator==(Poly const& a, Poly const& b)
{
    auto i = a.begin();
    auto j = b.begin();
    if(i->first==j->first)
        return true;
    else
        return false;
}

bool operator>(Poly const& a, Poly const& b)
{
    auto i = a.begin();
    auto j = b.begin();
    if(i->first>j->first)
        return true;
    else
        return false;

}

bool operator!=(Poly const& a, Poly const& b)
{
    auto i = a.begin();
    auto j = b.begin();
    if(i->first!=j->first)
        return true;
    else
        return false;

}

Poly::iterator Poly::begin()
{
    Poly::iterator i = this->m_values.rbegin();
    return i;
}

Poly::iterator Poly::end()
{
    Poly::iterator i = this->m_values.rend();
    return i;
}

Poly::const_iterator Poly::begin() const
{
    Poly::const_iterator i = this->m_values.rbegin();
    return i;
}

Poly::const_iterator Poly::end() const
{
    const_iterator i = this->m_values.rend();
    return i;
}

