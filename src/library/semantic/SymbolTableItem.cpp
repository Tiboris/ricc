#include "SymbolTableItem.hpp"

namespace RICC {

const std::map<SymbolTableItem::Type, std::string> SymbolTableItem::TypeMap{
    {SymbolTableItem::Type::BOOL, "BOOL"},
    {SymbolTableItem::Type::INT, "INT"},
    {SymbolTableItem::Type::FLOAT, "FLOAT"},
    {SymbolTableItem::Type::STRING, "STRING"},
    {SymbolTableItem::Type::VOID, "VOID"},
};

SymbolTableItem::SymbolTableItem(std::string key, Kind kind)
    : _key(key), _itemKind(kind), _type(VOID) {}

void SymbolTableItem::setType(Type t) { this->_type = t; }

SymbolTableItem::Type SymbolTableItem::getType() const { return this->_type; }

std::string SymbolTableItem::getName() const { return this->_key; }

void SymbolTableItem::setOffset(long offset) { this->_offset = offset; }

long SymbolTableItem::getOffset() const { return this->_offset; }

void SymbolTableItem::setStartAddress(long address) {
  this->_startAddress = address;
}

long SymbolTableItem::getStartAddress() const { return this->_startAddress; }

void SymbolTableItem::setJumpIndex(long address) { this->_jumpInstr = address; }

long SymbolTableItem::getJumpIndex() const { return this->_jumpInstr; }

void SymbolTableItem::addArg(Type t, const std::string& name) {
  this->_args.push_back({t, name});
}

std::vector<std::pair<SymbolTableItem::Type, std::string>>&
SymbolTableItem::getArgs() {
  return this->_args;
}

bool SymbolTableItem::isFunc() const { return this->_itemKind == FUNCTION; }

bool SymbolTableItem::isVar() const { return this->_itemKind == VARIABLE; }

void SymbolTableItem::print() const {
  if (this->isVar()) {
    std::cout << Token::getTokenTypeByText(
                     static_cast<Token::tokenType>(this->_type))
              << " " << this->_key << std::endl;
  } else if (this->isFunc()) {
    std::cout << Token::getTokenTypeByText(
                     static_cast<Token::tokenType>(this->_type))
              << " " << this->_key << "( ";
    for (auto& arg : this->_args) {
      std::cout << Token::getTokenTypeByText(
                       static_cast<Token::tokenType>(arg.first))
                << " " << arg.second << ", ";
    }
    std::cout << " )" << std::endl;
  }
}

}  // namespace RICC
