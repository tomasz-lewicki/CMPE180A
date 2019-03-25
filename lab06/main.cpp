#include <iostream>
#include <string>
#include <stack>

bool ishigherorequalprecedence(char stackTop, char symbol)
{
    if (stackTop == '!') return true;
    else if (stackTop == '^' && symbol != '!') return true;
    else if ( (stackTop == '/' || stackTop == '*') && symbol != '!' && symbol != '^') return true;
    else if ( (stackTop == '+' || stackTop == '+') && symbol != '!' && symbol != '^' && symbol != '*' && symbol != '/') return true;
    else return false;
}

std::string infixToPostfix(std::string infx)
{
    const std::string OPERATORS = "+-/*^!";
    const std::string OPERANDS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::stack<char> s;
    std::string pfx = "";
    
    for(auto sym = infx.begin(); sym != infx.end(); ++sym)
    {
        if( OPERANDS.find(*sym) != std::string::npos ) pfx += *sym;
        
        else if( *sym == '(') s.push('(');

        else if( *sym == ')')
        {
            while(s.top() != '(')
            {
                pfx += s.top();
                s.pop();
            }
            s.pop();
        }

        // case operator
        else if( OPERATORS.find(*sym) != std::string::npos )
        {
            if( s.empty() ) {}
            //else if ( s.top() == '(') {}
            else while(OPERATORS.find(s.top()) != std::string::npos && ishigherorequalprecedence(s.top(), *sym))
            {
                //as long as there's an operator of higher or equal precedence on the stack:
                pfx += s.top();
                s.pop();
                if(s.empty()) break;
            }
            s.push(*sym);
        }
    }

    while(!s.empty())
    {
        pfx += s.top();
        s.pop();
    }

    return pfx;
}

int main()
{
    std::cout << "Examples from the book:" << std::endl;
    std::cout << infixToPostfix("A+B-C") << std::endl;
    std::cout << infixToPostfix("(A+B)*C") << std::endl;
    std::cout << infixToPostfix("(A+B)*(C-D)") << std::endl;
    std::cout << infixToPostfix("A+((B+C)*(E-F)-G)/(H-I)") << std::endl;
    std::cout << infixToPostfix("A+B*(C+D)-E/F*GH") << std::endl;
    std::cout << infixToPostfix("a+b*(c^d-e)^(f+g*h)-i") << std::endl;
}