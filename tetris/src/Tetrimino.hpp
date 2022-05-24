#pragma once

#include "Block.hpp"
#include <array>
#include <map>

class Tetrimino : public sf::Drawable, public sf::Transformable {
public:
  enum class MoveDirection { Left, Right, Down, Up };

public:
  enum class Type { I, J, L, O, S, T, Z };
  enum class Rotate { A, B, C, D };

  Tetrimino(Type type, Rotate rotate);
  ~Tetrimino();

public:
  void setRotate(Rotate rotate);
  void rotate();
  void move(MoveDirection direction);
  bool isHit(const Block &fieldBlock) const;
  std::array<std::pair<int, int>, 4> getPoints() const;
  Block::Color getColor() const;

public:
  void setTypeWithRotate(Type type, Rotate rotate);
  Type getType() const;

private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
  Type type_{Type::I};
  Rotate rotate_{Rotate::A};
  std::array<Block, 4> blocks_;

  static std::map<Type, std::map<Rotate, std::array<std::pair<int, int>, 4>>> Patterns;
};
