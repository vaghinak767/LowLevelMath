#include <iostream>

double ast(double a, int n)
{
    double tmp = 1.0;
    for(int i = 0; i < n; ++i)
    {
        tmp *= a;
    }
    return tmp;
}

double ln(double a)
{
    double sum = 0.0;
    for(int i = 1; i < 1000; ++i)
    {
       sum += (ast((a - 1) / (a + 1), 2 * i - 1)) / (2 * i - 1);  
    }
    return 2 * sum;
}

double log(int a, int b)
{
    return ln(b) / ln (a);
}

void swap1(unsigned int& x, int i, int j)
{
    bool b = ((1 << i) & x);
    bool b1 = ((1 << j) & x);
    if(b1 != b)
    {
        x ^= (1 << i);
        x ^= (1 << j);
    }
}

void revers(unsigned int &x, int i, int j)
{
    if((x & (x - 1)) == 0)
    {
        swap1(x, i, j);
        return;
    }
    if(i > j)
    {
        while(i > j)
        {
            swap1(x, i, j);
            --i;
            ++j;
        }
    }
    else
        while(i < j)
        {
            swap1(x, i, j);
            ++i;
            --j;
        }
}

int sum_of_bit(int n, int m)
{
    int sum = 0;
    bool carry = 0;
    for(int i = 0; i < (sizeof(int) * 8); ++i)
    {
        sum ^= (((((n >> i) & 1) ^ ((m >> i) & 1)) ^ carry) << i);
        if(carry == 1 && ((n >> i) & 1) | ((m >> i) & 1))
        {
            carry |= ((n >> i) & 1) & ((m >> i) & 1);
        }
    else
        {
            carry = ((n >> i) & 1) & ((m >> i) & 1);
        }
    }
    return sum;
}

bool powOf4(int n)
{
    if(n < 1)
        return false;
    return !(n & (n - 1)) && ((n - 1) % 3 == 1);  
}

double armat(double n)
{
    double x = 1.0;
    for(int i = 0; i < 10; ++i)
    {
        x = (x + n / x) / 2;  
    }
    return x;
}

int amenamec_2(int n)
{
	if ((n & (n - 1)) == 0)
	{
		return n;
	}
	int a = 1;
	while (n > a)
	{
		a = a << 1;
	}
	return a >> 1;
}

int sum(int n, int m)
{
    while (m)
    {
        int c = n & m;
        n ^= m;
        m = c << 1;
    }
    return n;
}

int mul(int n, int m)
{
    int res = 0;
    while(m)
    {
        if(m & 1)
        {
            res = sum(res, n);
        }
        n <<= 1;
        m >>= 1;
    }
    return res;
}

int ast(int n, int m)
{
    int res = 1;
    int deg = 1;
    while(m)
    {
        int tmp = deg;
        while((tmp != 0) && ((m & 1) != 0))
        {
            res = mul(res, n);
            --tmp;
        }
        deg <<= 1;
        m >>= 1;
    }
    return res;
}

int main() 
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::cout << mul(n, m);
    return 0;
}
