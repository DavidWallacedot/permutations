//name:David Wallace
//date:10/19/2018
//purpose: this program prints out all permutations of inputed strings
//file name:permutations.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include<algorithm>

using namespace std;

bool twoElementsAscending(string array)

{
for(int i =0; i!=array.length();i++) 
	{
	if (array[i]<array[i+1])
		return true;
	}
	return false;
}
int findLargesti(string array)
{
	int i =-1;
	int index=1;
	while (index != array.length())
	{
		if (array[index-1]<array[index]) 
		{
			
			i = index -1;
			index++;			
//i = temp;
			
		}
		else{index++;}
	}
	
	return i;
}

int findLargestj(string array,int i)
{	int j;
	j = array.length()-1;
	while (j!=i){
	if(array[j]>array[i]){	return j;}
	j--;
	}
}

bool right_left = false;
bool left_right = true;

int searchArray(string input, int n, char mobile)
{
		for (int i = 0; i < n; i++)
		{
			if (input[i]==mobile)
			{
				return i;
			}
		}
}


char RetrieveMobile(string input, bool direction[], int n)
{
	
	char previous_mobile = 0;
	char mobile = 0;
	
	for (int i = 0; i < n; i++)
	{	
		
		if (direction[i] == right_left && i!=0)
		{	
			if (input[i]>input[i-1] && input[i]>previous_mobile)
			{
				mobile = input[i];
				previous_mobile = mobile;
				
			}
			
		}
		
		if (direction[i] == left_right && i!= (n-1))
		{
			if (input[i]>input[i+1] && input[i] >previous_mobile)
			{
				mobile = input[i];
				previous_mobile = mobile;
			}
		}
		
	}
	
	if (mobile == input[0] && previous_mobile == input[0])
	{
		return input[0];
	}
	else
	{
		return mobile;
	}
	
}

int fact(int n)
{
	int res = 1;
	
	for(int i = 1; i <= n; i++)
	{
		res = (res * i);
		
	}
	
	return res;

}

string PrintPerm (string input, bool direction[], int n, int counter)
{
	char mobile = RetrieveMobile(input,direction,n);
	
	int position = searchArray(input,n,mobile);
	
	
	if (direction[position] == right_left && position!=0)
	{
		
		char temp = input[position-1];
		input[position-1] = input[position];
		input[position]= temp;		
		bool tmp = direction[position-1];
		direction[position-1]= direction[position];
		direction[position] = tmp;
	}
		
	else if ( direction[position] == left_right)
	{
		
		char temp = input[position+1];
		input[position+1] = input[position];
		input[position]= temp;
		bool tmp = direction[position+1];
		direction[position+1]= direction[position];
		direction[position] = tmp;		
		
	}
	
	for (int i = 0; i < n; i++)
	{	
		if (input[i]>mobile)
		{
			if (direction[i] == left_right)
			{
				direction[i] = right_left;
			}
			else if (direction[i] == right_left)
			{
				direction[i] = left_right;
			}
		}
	}
	
		
	cout << counter << ":   ";
	for (int j = 0; j < n; j++)
	{
		if (direction[j] == 0)
		{
			cout << "<-";
			
		}
		else 
		{
			cout << "->";
			
		}
			}
		cout << endl;
		
	cout << "      ";
	for (int m = 0; m < n; m++)
	{
		
		cout << input[m];
		cout << " ";
			}
	cout << " " << endl;
	cout << " " << endl;
	return input;
}



void PrintAll( int size, string input)
{
	
	bool direction[size];
	
	int counter = 1;
	cout << counter << ":   ";
	for (int i = 0; i<size;i++)
	{cout<<"<-";}
	
	cout<<endl<<"      ";
	for (int i =0; i<size;i++)
	{cout<<input[i]<<" ";}
	cout<<endl;
		
	cout << endl;
	cout << endl;
	
	for (int i = 0; i < size; i++)
	{
		direction[i] = right_left;
	}
	counter++;
	for (int i = 1; i < fact(size); i++)
	{
		
		input = PrintPerm(input, direction, size, counter);
		counter++;
	}
	
}

void lexicographic(string origin)
{
	int i =0;
	int j = 0;
	int count =1;
	cout<<count<<":		"<<origin;
	count++;
	while (twoElementsAscending(origin))
	{
	i = findLargesti(origin);
	j = findLargestj(origin,i);
	cout<<"		i:"<<i<<"	j:"<<j<<endl;
	swap(origin[i],origin[j]);
	string temp = origin.substr(i+1);
	reverse(temp.begin(),temp.end());
	origin.erase(i+1);
	origin = origin+temp;
	cout<<count<<":		"<<origin;
	count++;
	}
}

int main()
{
	
	string input;
	int size;
	cout << "Enter in a string:    ";
	cout << " " <<endl;
	cin>> input;
	string origin = input;
	size = input.length();
	cout << "Johnson Trotter Algorithm" << endl;
	cout << "  " << endl;
	
	PrintAll(size,input);
	
	cout<<endl<<endl<<"LEXICOGRAPHIC ALGORITHM"<<endl;
	
	lexicographic(origin);
	
	cout<<endl<<"DONE!!"<<endl;
	return 0;
}





	
	
			
