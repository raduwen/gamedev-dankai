#include "Tetrimino.hpp"

std::map<Tetrimino::Type, std::map<Tetrimino::Rotate, std::array<std::pair<int, int>, 4>>> Tetrimino::Patterns{
    {Tetrimino::Type::I,
     {
         {Tetrimino::Rotate::A, {{{0, 1}, {1, 1}, {2, 1}, {3, 1}}}},
         {Tetrimino::Rotate::B, {{{2, 0}, {2, 1}, {2, 2}, {2, 3}}}},
         {Tetrimino::Rotate::C, {{{0, 2}, {1, 2}, {2, 2}, {3, 2}}}},
         {Tetrimino::Rotate::D, {{{1, 0}, {1, 1}, {1, 2}, {1, 3}}}},
     }},
    {Tetrimino::Type::O,
     {
         {Tetrimino::Rotate::A, {{{1, 1}, {2, 1}, {1, 2}, {2, 2}}}},
         {Tetrimino::Rotate::B, {{{2, 1}, {2, 2}, {1, 1}, {1, 2}}}},
         {Tetrimino::Rotate::C, {{{2, 2}, {1, 2}, {2, 1}, {1, 1}}}},
         {Tetrimino::Rotate::D, {{{1, 2}, {1, 1}, {2, 2}, {2, 1}}}},
     }},
    {Tetrimino::Type::J,
     {
         {Tetrimino::Rotate::A, {{{2, 1}, {0, 2}, {1, 2}, {2, 2}}}},
         {Tetrimino::Rotate::B, {{{2, 2}, {1, 0}, {1, 1}, {1, 2}}}},
         {Tetrimino::Rotate::C, {{{1, 2}, {3, 1}, {2, 1}, {1, 1}}}},
         {Tetrimino::Rotate::D, {{{1, 1}, {2, 3}, {2, 2}, {2, 1}}}},
     }},

    {Tetrimino::Type::S,
     {
         {Tetrimino::Rotate::A, {{{2, 1}, {3, 1}, {1, 2}, {2, 2}}}},
         {Tetrimino::Rotate::B, {{{2, 2}, {2, 3}, {1, 1}, {1, 2}}}},
         {Tetrimino::Rotate::C, {{{1, 2}, {0, 2}, {2, 1}, {1, 1}}}},
         {Tetrimino::Rotate::D, {{{1, 1}, {1, 0}, {2, 2}, {2, 1}}}},
     }},

    {Tetrimino::Type::Z,
     {
         {Tetrimino::Rotate::A, {{{1, 1}, {2, 1}, {2, 2}, {3, 2}}}},
         {Tetrimino::Rotate::B, {{{2, 1}, {2, 2}, {1, 2}, {1, 3}}}},
         {Tetrimino::Rotate::C, {{{2, 2}, {1, 2}, {1, 1}, {0, 1}}}},
         {Tetrimino::Rotate::D, {{{1, 2}, {1, 1}, {2, 1}, {2, 0}}}},
     }},
    {Tetrimino::Type::L,
     {
         {Tetrimino::Rotate::A, {{{1, 1}, {1, 2}, {2, 2}, {3, 2}}}},
         {Tetrimino::Rotate::B, {{{2, 1}, {1, 1}, {1, 2}, {1, 3}}}},
         {Tetrimino::Rotate::C, {{{2, 2}, {2, 1}, {1, 1}, {0, 1}}}},
         {Tetrimino::Rotate::D, {{{1, 2}, {2, 2}, {2, 1}, {2, 0}}}},
     }},
    {Tetrimino::Type::T,
     {
         {Tetrimino::Rotate::A, {{{1, 1}, {0, 2}, {1, 2}, {2, 2}}}},
         {Tetrimino::Rotate::B, {{{2, 2}, {1, 1}, {1, 2}, {1, 3}}}},
         {Tetrimino::Rotate::C, {{{1, 3}, {2, 2}, {1, 2}, {0, 2}}}},
         {Tetrimino::Rotate::D, {{{0, 2}, {1, 3}, {1, 2}, {1, 1}}}},
     }}};

Tetrimino::Tetrimino(Type type, Rotate rotate) { setTypeWithRotate(type, rotate); }

Tetrimino::~Tetrimino() {}

void Tetrimino::setRotate(Rotate rotate) { setTypeWithRotate(type_, rotate); }

// [todo] - left / right
void Tetrimino::rotate() {
  int rotate = static_cast<int>(rotate_);
  rotate++;
  if (rotate > static_cast<int>(Rotate::D)) {
    setRotate(Rotate::A);
  } else {
    setRotate(static_cast<Rotate>(rotate));
  }
}

void Tetrimino::move(MoveDirection direction) {
  switch (direction) {
  case MoveDirection::Left:
    sf::Transformable::move(-32.f, 0.f);
    break;
  case MoveDirection::Right:
    sf::Transformable::move(32.f, 0.f);
    break;
  case MoveDirection::Down:
    sf::Transformable::move(0.f, 32.f);
    break;
  case MoveDirection::Up:
    sf::Transformable::move(0.f, -32.f);
    break;
  }
}

bool Tetrimino::isHit(const Block &fieldBlock) const {
  auto p1 = getPosition();
  auto bpos = fieldBlock.getPosition();

  for (auto &block : blocks_) {
    auto p2 = block.getPosition();
    if (p1.x + p2.x == bpos.x && p1.y + p2.y == bpos.y) {
      return true;
    }
  }

  return false;
}

std::array<std::pair<int, int>, 4> Tetrimino::getPoints() const {
  std::array<std::pair<int, int>, 4> points;
  for (std::size_t i = 0; i < 4; ++i) {
    auto p = blocks_[i].getPosition();
    points[i] = std::make_pair(p.x / 32, p.y / 32);
  }
  return points;
}

Block::Color type2color(Tetrimino::Type type) {
  switch (type) {
  case Tetrimino::Type::I:
    return Block::Color::Cyan;
  case Tetrimino::Type::J:
    return Block::Color::Blue;
  case Tetrimino::Type::L:
    return Block::Color::Orange;
  case Tetrimino::Type::O:
    return Block::Color::Yellow;
  case Tetrimino::Type::S:
    return Block::Color::Green;
  case Tetrimino::Type::T:
    return Block::Color::Purple;
  case Tetrimino::Type::Z:
    return Block::Color::Red;
  }
}

void Tetrimino::setTypeWithRotate(Type type, Rotate rotate) {
  type_ = type;
  rotate_ = rotate;

  for (int i = 0; i < 4; i++) {
    blocks_[i].setPosition(Patterns[type_][rotate_][i].first * 32, Patterns[type_][rotate_][i].second * 32);
  }

  Block::Color c = type2color(type_);
  for (auto &block : blocks_)
    block.setColor(c);
}

Tetrimino::Type Tetrimino::getType() const { return type_; }

Block::Color Tetrimino::getColor() const { return type2color(type_); }

void Tetrimino::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  for (auto &block : blocks_) {
    target.draw(block, states);
  }
}
