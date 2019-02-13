# Templates

## Rationale
Templating is a mechanism allowing to overload functions with a single code segment.


## Syntax
Templates follow the following synatx:

```C++
template <class T> funcName; //for function templates
template <class T> class clsName; //for class templates
```

## Intuition behind it
In the same way as variables are parameters to functions, types are parameters to templates.

## Example
This way, instead of:
```
int larger(int x, int y);
char larger(char first, char second);
double larger(double u, double v);
string larger(string first, string second);
```

You can have the equivalent in a much more concise way:
```C++
template <class T>
Type larger(Type x, Type y)
{
    if(x >= y) return x;
    else return y;
}
```

## Class templates
Class templates can be seen as parametrized types - base on the template parameter type ('T') a specific class is generated.

An example of a well-known template from STL could be:
```C++
std::pair<int, double>
std::vector<double>
```

**Note**: because passing parameters to class templates happens at compile-time (unlike passing parameters to functions - at runtime)
