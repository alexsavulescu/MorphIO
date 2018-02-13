#pragma once

#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include <stdint.h>

#include <minimorph/vector_types.h>
#include <minimorph/enums.h>
#include <minimorph/exceptions.h>


#ifdef __GNUC__
#define BRAIN_UNUSED __attribute__((unused))
#else
#define BRAIN_UNUSED
#endif

// TODO: bcoste fix me
#include<iostream>
#define LBTHROW(x) (throw x)
#define LBERROR(x) (std::cerr << x << std::endl)
#define LBWARN std::cerr

/** @namespace minimorph Blue Brain File IO classes */
namespace minimorph
{
typedef std::string URI;

using namespace enums;
class Morphology;
class MorphologyInitData;
class Section;
class Soma;

namespace Property {
struct Properties;
}

namespace builder {
    class Section;
    class Soma;
    class Morphology;
}

template <typename T> class Iterator;
typedef std::pair<size_t, size_t> SectionRange;

typedef Iterator<std::stack<Section>> depth_iterator;
typedef Iterator<std::queue<Section>> breadth_iterator;
typedef Iterator<std::shared_ptr<Section>> upstream_iterator;

using PropertiesPtr = std::shared_ptr<Property::Properties>;
using MorphologyPtr = std::shared_ptr<Morphology>;
using ConstMorphologyPtr = std::shared_ptr<const Morphology>;
}

//TODO: compile
#if 0
// if you have a type T in namespace N, the operator << for T needs to be in
// namespace N too
namespace boost
{
template <typename T>
inline std::ostream& operator<<(std::ostream& os,
                                const boost::multi_array<T, 2>& data)
{
    for (size_t i = 0; i < data.shape()[0]; ++i)
    {
        for (size_t j = 0; j < data.shape()[1]; ++j)
            os << data[i][j] << " ";
        os << std::endl;
    }
    return os;
}
}

namespace std
{
template <class T, class U>
inline std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& pair)
{
    return os << "[ " << pair.first << ", " << pair.second << " ]";
}
}
#endif