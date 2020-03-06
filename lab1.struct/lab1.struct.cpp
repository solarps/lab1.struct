#include <iostream>
using namespace std;

struct Date {
    short day;
    short month;
    short year;
    bool isCorrect();
};
bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}
struct product
{
	char name[56];
	Date release;
	int quantity;
	int price;
	char manufactor[56];
};
void lvl1()
{
	const int N = 2;
	product group[N];

	for (int i = 0; i < N; i++)
	{
		cout << "\nInput name: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].name, 56);

		cout << "\nInput manufactor: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].manufactor, 56);

		do
		{
			cout << "\nInput birthday: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].release.day >> group[i].release.month >> group[i].release.year;
		} while (!group[i].release.isCorrect());

		cout << "\nInput quantity:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].quantity;

		cout << "\nInput price:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].price;

		cin.clear();
	}

	int best = 0;
	for (int i = 0; i < N; i++)
	{
		if (group[i].quantity*group[i].price > group[best].quantity*group[best].price)
			best = i;
	}
	cout << "The most expensive:" << group[best].name;
}

struct time 
{
 double hour;
 double min;
 bool isCorrect();
};

bool time::isCorrect()
{
    bool result = false;
    if ((hour <= 24) && (hour >= 0)) {
        result = true;
    }
    if ((min >= 0) && (min <= 60)){
        result = true;
    }
    return result;
}

struct train
{
 int number;
 time arrival;
 time departure;
 char route[56];
 int distance;
};

void lvl2()
{
    const int N = 2;
    train group[N];

    for (int i = 0; i < N; i++)
    {
        cout << "\nInput number: ";
        cin >> group[i].number;

        do
        {
            cout << "\nInput arrival time: ";
            cin >> group[i].arrival.hour >> group[i].arrival.min;
        } while (!group[i].arrival.isCorrect());

        do
        {
            cout << "\nInput departure time: ";
            cin >> group[i].departure.hour >> group[i].departure.min;
        } while (!group[i].departure.isCorrect());

        cout << "\nInput route:";
        cin >> group[i].route;

        cout << "\nInput distance:";
        cin >> group[i].distance;

        if (group[i].departure.min < group[i].arrival.min) group[i].departure.hour += 1;
        cout << "\nAmount speed:" << group[i].distance / (group[i].departure.hour - group[i].arrival.hour + (group[i].departure.min - group[i].arrival.min) / 60);

    }

    for (int i = 0; i < N; i++)
    {
        cout << "\nAmount speed" << i + 1 << "train" << group[i].distance / (group[i].departure.hour - group[i].arrival.hour + (group[i].departure.min - group[i].arrival.min) / 60);
    }

}
struct name
{
    char F[56];
    char I[32];
    char O[32];
};
struct NOTE2
{
    name user;
    int tele;
    Date birthday;
	bool isCorrect();
};
bool NOTE2::isCorrect()
{
	bool result = false;
	if ((tele > 1000000000) && (tele < 9999999999)) result = true;
	return result;
}

void lvl3()
{
    const int N = 7;
    NOTE2 BLOCK2[N];

    for (int i = 0; i < 2; i++)
    {
		cout << "\nInput F: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCK2[i].user.F, 56);

		cout << "\nIinput I: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCK2[i].user.I, 32);

		cout << "\nInput O: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCK2[i].user.O, 32);

        cout << "\nInput telephone: ";
        cin >> BLOCK2[i].tele;

		do
		{
			cout << "\nInput birthday: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> BLOCK2[i].birthday.day >> BLOCK2[i].birthday.month >> BLOCK2[i].birthday.year;
		} while (!BLOCK2[i].birthday.isCorrect());

    }

	for (int i = 0; i < N; i++) {
		if (BLOCK2[i].tele / 1000000 > BLOCK2[i + 1].tele / 1000000)
		{
			swap(BLOCK2[i].user.F, BLOCK2[i + 1].user.F);
			swap(BLOCK2[i].user.I, BLOCK2[i + 1].user.I);
			swap(BLOCK2[i].user.O, BLOCK2[i + 1].user.O);
			swap(BLOCK2[i].tele, BLOCK2[i + 1].tele);
			swap(BLOCK2[i].birthday.day, BLOCK2[i + 1].birthday.day);
			swap(BLOCK2[i].birthday.month, BLOCK2[i + 1].birthday.month);
			swap(BLOCK2[i].birthday.year, BLOCK2[i + 1].birthday.year);
		}

	}

    char userf[56];
	int k = 0;
    cout << "\nInput famil of user: ";
    cin >> userf;
    for (int i = 0; i < N; i++) {
        if (userf == BLOCK2[i].user.F)
        {
            cout << "FIO:" << BLOCK2[i].user.F << " " << BLOCK2[i].user.I << " " << BLOCK2[i].user.O << endl;
            cout << "Telephon number:" << BLOCK2[i].tele << endl;
            cout << "Birthdat:" << BLOCK2[i].birthday.day << "." << BLOCK2[i].birthday.month << "." << BLOCK2[i].birthday.year;
			k += 1;
		}
    }
	if (k = 0)
	{
		cout << "No matches" << endl;
	}
}
int main()
{
	int a;
	while (true)
	{
		cout << "Numbers of levels are 1 2 3 \n";
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1:
			lvl1();
			break;
		case 2:
			lvl2();
			break;
		case 3:
			lvl3();
			break;
		case 0:
			return(0);
			break;
		default:
			cout << "Incorrect number, try again" << endl;
			break;
		}
	}
}
