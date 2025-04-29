#include <iostream>
#include <map>
#include <ctime>
#include <vector>

class Currency {
private:
    std::string code;
    std::string name;
    double rateToUSD; // Exchange rate to USD

public:
    Currency(std::string code, std::string name, double rate)
        : code(code), name(name), rateToUSD(rate) {
    }

    double convertTo(double amount, const Currency& target) const {
        return amount * (rateToUSD / target.rateToUSD);
    }

    // Getters
    std::string getCode() const { return code; }
    double getRate() const { return rateToUSD; }
};

class ExchangeRate {
private:
    std::map<std::string, double> rates; // Map of currency codes to USD rates

public:
    void updateRate(const std::string& code, double rate) {
        rates[code] = rate;
    }

    double getRate(const std::string& from, const std::string& to) const {
        return rates.at(from) / rates.at(to);
    }
};

class Transaction {
private:
    std::string id;
    std::string accountId;
    double amount;
    std::string currency;
    std::string category;
    time_t date;
    std::string description;

public:
    Transaction(std::string id, std::string acc, double amt,
        std::string curr, std::string cat, std::string desc)
        : id(id), accountId(acc), amount(amt), currency(curr),
        category(cat), description(desc) {
        date = time(0);
    }

    void display() const {
        std::cout << std::ctime(&date) << " - " << amount << " " << currency
            << " (" << category << "): " << description << "\n";
    }
};

class FinancialSystem {
private:
    std::map<std::string, Currency> currencies;
    ExchangeRate exchange;
    std::vector<Transaction> transactions;

public:
    void addCurrency(const Currency& c) {
        currencies[c.getCode()] = c;
        exchange.updateRate(c.getCode(), c.getRate());
    }

    void addTransaction(const Transaction& t) {
        transactions.push_back(t);
    }

    double convertCurrency(double amount, const std::string& from, const std::string& to) {
        return amount * exchange.getRate(from, to);
    }

    void displayTransactions() const {
        for (const auto& t : transactions) t.display();
    }
};