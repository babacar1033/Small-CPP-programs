#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

void readFile(ifstream& inF, string& fileN);
void wordCount(ifstream& inF, ofstream& outF, int& lgst, int& shtst, string fileN);
void wordLongest(ifstream& inF, ofstream& outF, int& lgst, string fileN);
void wordShortest(ifstream& inF, ofstream& outF, int shtst, string fileN);
void wordSearch(ifstream& inF, ofstream& outF, string fileN);

int main(){

    ofstream fileO;
    ifstream fileI;
    char outputFile[20];
    int longest, shortest, choice;
    string file;

    cout << " would you please enter the output filename ?: ";
    cin >> outputFile;
    fileO.open(outputFile);
    

    do {

    	cout << "Select an option:\n"
    		 << "\t 1- Enter input file name\n"
    		 << "\t 2 - Determine various statistics of present words\n"
			 << "\t 3- List shortest words\n"
			 << "\t 4- List longest words\n"
			 << "\t 5- Search for a word\n"
			 << "\t 6- Exit \n";
		cin >> choice;

		switch(choice)
		{
			case 1:
				readFile(fileI, file);
				break;
			case 2:
			    if (!fileI.is_open())
				{
                    cout << "Input file not found.\n";
                    break;
			    }
				wordCount(fileI, fileO, longest, shortest, file);
				break;
			case 3:
			    if (!fileI.is_open())
				{
                    cout << "Input file not found.\n";
                    break;
			    }
				wordShortest(fileI, fileO, shortest, file);
				break;
			case 4:
			    if (!fileI.is_open())
				{
                    cout << "Input file not found.\n";
                    break;
			    }
				wordLongest(fileI, fileO, longest, file);
				break;
			case 5:
			    if (!fileI.is_open())
				{
                    cout << "file input not found.\n";
                    break;
			    }
				wordSearch(fileI, fileO, file);
				break;
			case 6:
				cout << "seee yaah buddy ! \n";
				exit(1);
				break;
			default:
				cout << "Invalid option.\n";
				break;

		}


	} while (choice != 6);

    fileI.close();
    fileO.close();
}

void readFile(ifstream& inF, string& fileN)
{

	char inpFile[20];

    if (inF.is_open())
    {
        inF.close();
    }

    cout << "Enter input file name: ";
    cin >> inpFile;
    cout << "File name entered: " << inpFile << endl;
    inF.open(inpFile);

    fileN = inpFile;

    if (inF.fail())
	{
        cout << "Input file opening failed.\n";
        exit(1);
    }
}

void wordCount(ifstream& inF, ofstream& outF, int& lgst, int& shtst, string fileN){

    inF.clear();
    inF.seekg(0);
    int wordCounter = 0, sumLength = 0, punctuationC = 0, sizeW;
    double avgL;
    string word;
    lgst = 0;
    shtst = 100;

    while (inF >> word)
	{
        wordCounter++;
        sizeW = word.length();
        while (ispunct(word.at(word.length()-1)))
		{
            
            punctuationC++;
            word.erase(sizeW-1,1);
            sizeW--;
        }
        
        
        while (ispunct(word.at(0)))
		{
    		punctuationC++;
            word.erase(0,1);
            sizeW--;
        }
        
        sumLength += sizeW;
        if (sizeW > lgst)
            lgst = sizeW;
        if (sizeW <  shtst)
        	shtst = sizeW;
    }
        
    avgL = (double)sumLength / wordCounter;

    cout << "File name: " << fileN << endl
         << "Total number of words = " << wordCounter << endl
         << "Average word length = " << avgL << " characters.\n"
         << "Total number of word characters = " << sumLength << endl
         << "Shortest word length = " << shtst << endl
         << "Longest word length = " << lgst << endl
         << "Number of punctuation characters = " << punctuationC << endl;

    outF << "File name: " << fileN << endl
         << "Total number of words = " << wordCounter << endl
         << "Average word length = " << avgL << " characters.\n"
         << "Shortest word length = " << shtst << endl
         << "Longest word length = " << lgst << endl
         << "Number of punctuation characters = " << punctuationC <<endl;

}

void wordLongest(ifstream& inF, ofstream& outF, int& lgst, string fileN)

{

    inF.clear();
    inF.seekg(0);

    string word;
    

    int sizeW;

			cout << "File name: " << fileN << endl
        		 << "Longest words in the file: \n";
    		outF << "File name: " << fileN << endl
         		 << "Longest words in the file: \n";
    
    
	while (inF >> word)
	
{

        sizeW=word.length();
        
        while (ispunct(word.at(word.length()-1)))
		{
            word.erase(sizeW-1,1);
            sizeW--;
        }
        
        
        while (ispunct(word.at(0)))
	{
        word.erase(0,1);
        sizeW--;
 	}
        


	if (sizeW >= lgst)
	{

            lgst = sizeW;
    
        if (word.length() == lgst)
		{		 
         		 cout<<word<<endl;
         		 outF<<word<<endl;
        }
    }
}
}




void wordShortest(ifstream& inF, ofstream& outF, int shtst, string fileN)
{
	inF.clear();
    inF.seekg(0);

    string word;
    int sizeW;

			cout << "File name: " << fileN << endl
        		 << "shortest words in the file: \n";
    		outF << "File name: " << fileN << endl
         		 << "shortest words in the file: \n";
    
    
	while (inF >> word)
	
{

        
        sizeW=word.length();
        
        while (ispunct(word.at(word.length()-1)))
		{
            
            
            word.erase(sizeW-1,1);
            sizeW--;
           
        }
        
        
        while (ispunct(word.at(0)))
	{
            word.erase(0,1);
            sizeW--;
 	}
        


	if (sizeW <= shtst)
	{

    	shtst = sizeW;
    
    	if (word.length() == shtst)
		{		 
         	cout<<word<<endl;
         	outF<<word<<endl;
        }
    }
}

}

    

void wordSearch(ifstream& inF, ofstream& outF, string fileN){

    inF.clear();
    inF.seekg(0);

    string word, search;
    int sizeW;
    int fd = 0;

    cout << "Search word: ";
    cin >> search;
    while (inF >> word)
	{
       sizeW=word.length();
        
        while (ispunct(word.at(word.length()-1)))
		{
            
            
            word.erase(sizeW-1,1);
            sizeW--;
           
        }
        
        
        while (ispunct(word.at(0)))
	{
            word.erase(0,1);
            sizeW--;
 	}
        if (word == search)
        {
		
            fd++;
        }
    }
    cout << "\nFile name: " << fileN << endl
         << "The word \"" << search << "\" appears " << fd << " time(s) in the file.\n";
    outF << "File name: " << fileN << endl
         << "The word \"" << search << "\" appears " << fd << " time(s) in the file.\n";
}




