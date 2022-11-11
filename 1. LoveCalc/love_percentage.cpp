#include<iostream>
#include<cstring>
using namespace std ;

void perct( char , char );
void line( int* line_in , int totx);		 // last output is here

int main() 	
{
	char name1[100],name2[100];
	cout << " Enter Your First Name : ";
	cin >> name1 ;
	cout << " Enter Your Cursh's First Name : ";
	cin >> name2 ;
	
	// Processing Starts From Here
	
	int len1 = strlen(name1) , len2 = strlen(name2) ;  	//lengths of names
	int tot = len1+len2+4  ; 	// Total letters
	char full_line[tot+1] ;
	int  line1[tot] ;
	int i,j ;  		//initializing Variables 
	char love[5] = { 'l' ,'o' , 'v' , 'e' } ;
	
	strcat( full_line , name1 ) ;
	strcat( full_line , love ) ;
	strcat( full_line , name2 ) ;
	
	
	for ( i=0 ; i<=tot ; i++ )			// in full_name total no.of element is (tot+1) including zero
	{
		line1[i] = 1;					// in line1 total no.of elemwnt is (tot)
		for ( j=tot ; j>i ; j-- )		
		{
			
				if ( full_line[i] == full_line[j] )			
				{
					line1[i] = line1[i] + 1 ;			// 'line1' is the first line of calculation
					
					for(int del=j ; del<=tot-1 ; del++ )  	// THIS LOOP IS TO REMOVED (CANCEL) THE SAME LETTER
					{
						full_line[del]= full_line[del+1] ; 
					}
					tot = tot -1 ; // Now One Elment is deleted
				}}}

	cout << "\n\t";
	for( i=0 ; i<tot ; i++)		// 'tot' will be same for first calculation line 'line1'
	{
		cout << line1[i];			
	}
	
	// First Line Finished
	cout << endl <<'\t' << "  " ;
	
	line(line1, tot) ; 		// To Calculate Next Line
}

void line( int* line_in , int totx ) // totx = total no.of word outside this function
{	
	int *line_out , emty[100]={0};
	int toty,i,j;
	
	line_out = &emty[0];
			
	if( totx %2 != 0) 	//it is odd
	{
		toty = (totx/2)+1;		// 2nd Line length
		*(line_out + (toty-1)) = *(line_in + (totx-1)/2);	// Middle Number of 1st line remains same and will be in the end of 2nd line
	}
	else
		toty = totx/2 ; 
	for(i=0 ; i<totx ; i++)
	{
		j = totx-1 ;
		if( j>i )
		{
			*(line_out + i) = *(line_in+i) + *(line_in + j) ;	// Adding elements
			*(line_in + j) = 0;
			totx = totx-1;			
		}}	// Now Number of elements in totx = toty
		
	// New Line Finished
	
	if( toty > 2)
	{
		for(i=0 ; i<toty ; i++)				
			cout << *(line_out + i);	// Printing the line
	
		line(line_out,totx); // repeat this function until the total no.of elements in line is 2
	}
	cout << endl << '\t' << "   ";
	if ( toty == 2 )
	{
		int arr[2] , arr2[2] ;
		
		arr[0] = 0 ; arr[1] = 0 ; 
		arr2[0] = 0 ; arr2[1] = 0 ;
		//if ( *(line_out + 0) > 9 || *(line_out +1) > 9 )
		//{
			//for(i=0 ; i>2 ; i++)
			//{
			if ( *(line_out + 0) > 9 )
			{				
				arr[0] = *(line_out +0) / 10;
				arr[1] = *(line_out +0) % 10;
				flag = 1 ;
			}
			if ( *(line_out + 1) > 9 )
			{
				arr2[0] = *(line_out +1) / 10;
				arr2[1] = *(line_out +1) % 10;
				flag = flag + 1 ;
			}
				
			//}
		//}
		
		char choice ;
		cout << "\n Percentage = " << *line_out << *(line_out +1) << '%' << endl;
		cout << "\n \n Do you Want to continue (y/n) : ";
		x:
		cin >> choice;
		if ( choice == 'n' || choice == 'N' )
		{
			exit (0);
		}

		else if ( choice == 'y' || choice == 'Y' )
		{
			system("clear");
			main();
		}

		else
		{
			cout<< "\n \t Wrong Input \n \n Type Again : " ;
			goto x;
	
		}
	}
}
