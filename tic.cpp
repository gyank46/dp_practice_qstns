#include <iostream>
#include <time.h>
using namespace std;

char pos[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board(char sign1,char sign2);

int main()
{
	int player = 1,choice,mode;
	char sign1,sign2;
	cout<<"Enter 1 for Player Vs computer.\nEnter 2 for Player vs Player.\n";
	cin>>mode;
	if(mode==2)
	{

		cout<<"Player "<<player<<" choose a Sign('X' or 'O'): ";
		cin>>sign1;
		if(sign1=='X')
			sign2='O';
		else
			sign2='X';
		cout<<endl;
		while(checkwin()==-1)
		{
			board(sign1,sign2);
			player=(player%2)?1:2;
			cout<<"Player "<<player<<" enter your choice: ";
			cin>>choice;
			if((choice>=1&&choice<=9)&&pos[choice]==choice+48)
			{
				if(player==1)
					pos[choice]=sign1;
				else
					pos[choice]=sign2;
			}
			else
			{
				cout<<"Invalid Move. \n";
				player--;
				cin.ignore();
				cin.get();
			}
			player++;
		}

	}
	if(mode==1)
	{
		cout<<"Player "<<player<<" choose a Sign('X' or 'O'): ";
		cin>>sign1;
		if(sign1=='X')
			sign2='O';
		else
			sign2='X';
		cout<<endl;
		while(checkwin()==-1)
		{
			board(sign1,sign2);
			player=(player%2)?1:2;
			if(player==1)
			{
				cout<<"Player "<<player<<" enter your choice: ";
				cin>>choice;
				if((choice>=1&&choice<=9)&&pos[choice]==choice+48)
					pos[choice]=sign1;
				else
				{
					cout<<"Invalid Move. \n";
					player--;
					cin.ignore();
					cin.get();
				}
				player++;
			}
			else
			{
				choice=rand()%10;
				if(choice==0)
					choice++;
				while(pos[choice]!=choice+48)
				{
					choice=rand()%10;
					if(choice==0)
						choice++;
				}
				pos[choice]=sign2;
				player++;
			}
		}

	}
	board(sign1,sign2);
	if(checkwin()==1)

		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";

	cin.ignore();
	cin.get();
	return 0;
}


int checkwin()
{
	if (pos[1] == pos[2] && pos[2] == pos[3])

		return 1;
	else if (pos[4] == pos[5] && pos[5] == pos[6])

		return 1;
	else if (pos[7] == pos[8] && pos[8] == pos[9])

		return 1;
	else if (pos[1] == pos[4] && pos[4] == pos[7])

		return 1;
	else if (pos[2] == pos[5] && pos[5] == pos[8])

		return 1;
	else if (pos[3] == pos[6] && pos[6] == pos[9])

		return 1;
	else if (pos[1] == pos[5] && pos[5] == pos[9])

		return 1;
	else if (pos[3] == pos[5] && pos[5] == pos[7])

		return 1;
	else if (pos[1] != '1' && pos[2] != '2' && pos[3] != '3'
                    && pos[4] != '4' && pos[5] != '5' && pos[6] != '6'
                  && pos[7] != '7' && pos[8] != '8' && pos[9] != '9')

		return 0;
	else
		return -1;
}


void board(char sign1,char sign2)
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 ("<<sign1<<")  -  Player 2 ("<<sign2<<")" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << pos[1] << "  |  " << pos[2] << "  |  " << pos[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << pos[4] << "  |  " << pos[5] << "  |  " << pos[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << pos[7] << "  |  " << pos[8] << "  |  " << pos[9] << endl;

	cout << "     |     |     " << endl << endl;
}
