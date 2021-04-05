#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Quote {
public:
  Quote() = default;
  Quote(const std::string &book, double sales_prices)
      : bookNO(book), price(sales_prices) {}
  virtual ~Quote() = default;

  std::string isbn() const { return bookNO; }
  virtual double net_price(size_t n) const { return n * price; }

private:
  std::string bookNO;

protected:
  double price = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold:" << n << " total due: " << ret
     << endl;
  return ret;
}

int main() { return 0; }