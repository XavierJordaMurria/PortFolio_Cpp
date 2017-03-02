#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

using namespace std;

long long solution()
{
    ifstream myfile;
    myfile.open ("names.txt", ios::in);
    long long finalResult = 0;
    
    vector<string> result;
    
    if (myfile)
    {
        stringstream buffer;
        
        buffer << myfile.rdbuf();
        
        myfile.close();
        
        while( buffer.good())
        {
            string substr;
            getline( myfile, substr, ',');
            result.push_back( substr );
        }
        
        sort( result.begin(), result.end() );
        
        
        string tmpStr;
        int sum = 0;
        
        for(int i =0; i< result.size(); i++)
        {
            tmpStr = result.at(i);
            tmpStr.erase(std::remove(tmpStr.begin(), tmpStr.end(), '"'), tmpStr.end());
            sum = 0;
            
            for(int j = 0; j < tmpStr.size(); j++)
                sum += tmpStr[j]- 'A' + 1;
            
            finalResult += (i+1) * sum;
        }
    }
    
    return finalResult;
}

int main()
{
    long long answer = solution();

    std::cout << "Solution: " << answer << " is " <<
        (answer == 871198282 ? "correct" : "wrong" ) 
        << "\n";

    return 0;
}

