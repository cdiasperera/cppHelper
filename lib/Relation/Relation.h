#ifndef RELATION_h_1682948508
#define RELATION_h_1682948508

#include <cstddef>
#include <unordered_map>
#include <unordered_set>

// This class defines a general mathematical relation
template <typename Data>
class Relation
{
  friend bool operator==(Relation const &r1, Relation const &r2);

  using AdjMatrix = std::unordered_map<Data, std::unordered_map<Data, bool>>;
  using Set = std::unordered_set<Data>;

  AdjMatrix d_adjMatrix;
  Set d_universe;

  public:
    // Constructors
    Relation() = default;
    Relation(Relation const &other) = default;

    // Assignment operators
    Relation<Data> &operator=(Relation const &other);

    // Relation specific functions
    void relate(Data const &from, Data const &to);
    Relation<Data> transitiveClosure();
    Relation<Data> reflexiveClosure();

  private:
    void addToUniverse(Data const &elem);
    void swap(Relation &other);
};

template <typename Data>
void Relation<Data>::swap(Relation &other)
{
  d_adjMatrix.swap(other.d_adjMatrix);
  d_universe.swap(other.d_universe);
}

template <typename Data>
Relation<Data> &Relation<Data>::operator=(Relation<Data> const &other)
{
  Relation<Data> tmp{other};
  swap(tmp);

  return *this;
}



template <typename Data>
void Relation<Data>::addToUniverse(const Data &elem)
{

  if (not d_universe.contains(elem))
    for (auto const &existing : d_universe)
    {
      d_adjMatrix[existing][elem] = false;
      d_adjMatrix[elem][existing] = false;
    }
  d_universe.insert(elem);
}

template <typename Data>
void Relation<Data>::relate(Data const &from, Data const &to)
{
  addToUniverse(from);
  addToUniverse(to);

  d_adjMatrix[from][to] = true;
}

template <typename Data>
Relation<Data> Relation<Data>::transitiveClosure()
{
  Relation<Data> closure = *this;
  AdjMatrix &closureMat = closure.d_adjMatrix;

  for (auto const &k : d_universe)
    for (auto const &i : d_universe)
      for (auto const &j : d_universe)
        closureMat[i][j] =
          closureMat[i][j] or (closureMat[i][k] and closureMat[k][k]);

  return closure;
}

template <typename Data>
Relation<Data> Relation<Data>::reflexiveClosure()
{
  Relation<Data> closure = *this;
  AdjMatrix &closureMat = closure.d_adjMatrix;

  for (auto const &elem : d_universe)
    closureMat[elem][elem] = true;

  return closure;
}

template <typename Data>
bool operator==(Relation<Data> const &r1, Relation<Data> const &r2)
{
  if (not r1.d_universe == r2.d_universe)
    return false;

  auto const &universe = r1.d_universe;
  for (auto const &i : universe)
    for (auto const &j : universe)
      if (r1.d_adjMatrix[i][j] != r2.d_adjMatrix[i][j])
        return false;

  return true;
}

#endif
