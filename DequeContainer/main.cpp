#include <iostream>
#include "Deque.h"


//Main Menu Enum
enum EMenu
{
	Menu,
	Enqueue_Front,
	Enqueue_Back,
	Dequeue_Front,
	Dequeue_Back,
	Peek_Front,
	Peek_Back,
	IsEmpty,
	Exit,
};

//Clear input function
void ClearInput();

//Enter to continue function
void EnterContinue();


int main()
{
	CDeque* dequeList = new CDeque; //create a Deque list

	//Initialise Variables
	int iMenuInput = Menu; //Main menu choice variable - Starting at main menu
	int iInputData = 0; //Variable to hold input value to be tranferred to Deque functions.
	
	do
	{
		if (std::cin.fail() || (iMenuInput < Menu || iMenuInput > Exit))
		{
			ClearInput();
			system("CLS");
			std::cout << "Input not accepted." << std::endl;
			std::cout << "Only enter one of the below choices" << std::endl;
		}

		//Show main menu options
		std::cout << std::endl << "Deque Container using LinkedList" << std::endl << std::endl;
		std::cout << "1. Enqueue_Front" << std::endl;
		std::cout << "2. Enqueue_Back" << std::endl;
		std::cout << "3. Dequeue_Front" << std::endl;
		std::cout << "4. Dequeue_Back" << std::endl;
		std::cout << "5. Peek_Front" << std::endl;
		std::cout << "6. Peek_Back" << std::endl;
		std::cout << "7. IsEmpty" << std::endl;
		std::cout << "8. Exit" << std::endl << std::endl;
		
		std::cout << "Please enter your choice: ";
		std::cin >> iMenuInput; //get user input for menu


		switch (iMenuInput)
		{
			case Enqueue_Front:
			{
				std::cout << std::endl << "Enter integer to be placed into front of list: ";
				std::cin >> iInputData;
				dequeList->Enqueue_Front(iInputData);
				EnterContinue();
				break;
			}

			case Enqueue_Back:
			{
				std::cout << std::endl << "Enter integer to be placed into back of list: ";
				std::cin >> iInputData;
				dequeList->Enqueue_Back(iInputData);
				EnterContinue();
				break;
			}

			case Dequeue_Front:
			{
				dequeList->Dequeue_Front();
				EnterContinue();
				break;
			}

			case Dequeue_Back:
			{
				dequeList->Dequeue_Back();
				EnterContinue();
				break;
			}

			case Peek_Front:
			{
				std::cout << std::endl;
				dequeList->Peek_Front();
				EnterContinue();
				break;
			}

			case Peek_Back:
			{
				std::cout << std::endl;
				dequeList->Peek_Back();
				EnterContinue();
				break;
			}

			case IsEmpty:
			{
				std::cout << std::endl;
				if (dequeList->IsEmpty() == 0)
				{
					std::cout << "False." << std::endl;
				}
				else
				{
					std::cout << "True." << std::endl;
				}
				EnterContinue();
				break;
			}

			default:
			{

			}
		}
	} while (iMenuInput != Exit);

	// ..........  Program Exit ..............
	if (iMenuInput == Exit)
	{
		system("CLS");
		std::cout << std::endl << std::endl;
		std::cout << "Exiting Deque Container Program" << std::endl;
		std::cout << std::endl;
		std::cout << "Press Enter to Exit";
		std::cin.ignore();
		std::cin.ignore(); //These ignores required otherwise game will exit without showing above text
	}

	return 0;
}

void ClearInput() //Clear input function
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

void EnterContinue() //Enter to continue function
{
	std::cout << std::endl;
	std::cin.ignore();
	std::cout << "Press Enter to continue.";
	std::cin.ignore();
	system("CLS");
}