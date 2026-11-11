#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

// Task 1. Student and Aspirant
class Student
{
protected:
	char* name;
	int age;
	char* university;
	char* speciality;

	static char* copyString(const char* str)
	{
		char* result = new char[strlen(str) + 1];
		strcpy_s(result, strlen(str) + 1, str);
		return result;
	}

public:
	Student() : name(copyString("NoInfo")), age(0),
		university(copyString("NoInfo")), speciality(copyString("NoInfo")) {}

	Student(const char* name, int age, const char* university, const char* speciality)
		: name(copyString(name)), age(age), university(copyString(university)),
		speciality(copyString(speciality)) {}

	Student(const Student& other)
		: name(copyString(other.name)), age(other.age),
		university(copyString(other.university)), speciality(copyString(other.speciality)) {}

	Student& operator=(const Student& other)
	{
		if (this == &other)
			return *this;

		delete[] name;
		delete[] university;
		delete[] speciality;

		name = copyString(other.name);
		age = other.age;
		university = copyString(other.university);
		speciality = copyString(other.speciality);

		return *this;
	}

	virtual void showInfo() const
	{
		cout << "Name: " << name << "\nAge: " << age
			<< "\nUniversity: " << university
			<< "\nSpeciality: " << speciality << endl;
	}

	virtual ~Student()
	{
		delete[] name;
		delete[] university;
		delete[] speciality;
	}
};
class Aspirant : public Student
{
protected:
	char* projectName;
	char* supervisor;
	char* enrollmentYear;
	bool dissertationStatus;

public:
	Aspirant() : Student(), projectName(copyString("NoInfo")),
		supervisor(copyString("NoInfo")), enrollmentYear(copyString("NoInfo")),
		dissertationStatus(false) {}

	Aspirant(const char* name, int age, const char* university, const char* speciality)
		: Aspirant(name, age, university, speciality, "NoInfo", "NoInfo", "NoInfo", false) {}

	Aspirant(const char* name, int age, const char* university, const char* speciality,
		const char* projectName, const char* supervisor, const char* enrollmentYear,
		bool dissertationStatus)
		: Student(name, age, university, speciality), projectName(copyString(projectName)),
		supervisor(copyString(supervisor)), enrollmentYear(copyString(enrollmentYear)),
		dissertationStatus(dissertationStatus) {}

	Aspirant(const Aspirant& other)
		: Student(other), projectName(copyString(other.projectName)),
		supervisor(copyString(other.supervisor)), enrollmentYear(copyString(other.enrollmentYear)),
		dissertationStatus(other.dissertationStatus) {}

	Aspirant& operator=(const Aspirant& other)
	{
		if (this == &other)
			return *this;

		Student::operator=(other);
		delete[] projectName;
		delete[] supervisor;
		delete[] enrollmentYear;

		projectName = copyString(other.projectName);
		supervisor = copyString(other.supervisor);
		enrollmentYear = copyString(other.enrollmentYear);
		dissertationStatus = other.dissertationStatus;

		return *this;
	}

	void showInfo() const override
	{
		Student::showInfo();
		cout << "Project: " << projectName << "\nSupervisor: " << supervisor
			<< "\nEnrollment year: " << enrollmentYear
			<< "\nDissertation status: " << (dissertationStatus ? "Yes" : "No") << endl;
	}

	void workOnResearch()
	{
		cout << name << " is working on scientific research: " << projectName << endl;
	}

	~Aspirant()
	{
		delete[] projectName;
		delete[] supervisor;
		delete[] enrollmentYear;
	}
};

// Task 2. Passport and ForeignPassport
class Passport
{
private:
	static bool IsValidDateFormat(const char date[])
	{
		if (strlen(date) != 10)
			return false;

		if (date[2] != '.' || date[5] != '.')
			return false;

		return true;
	}

protected:
	char* fullName;
	char* dateOfBirth;
	char* passportNumber;
	char* nationality;
	char* dateOfIssue;
	char* expiryDate;
	int issuingAuthority;
	int countOfErrors = 0;

	static char* copyString(const char* str)
	{
		char* result = new char[strlen(str) + 1];
		strcpy_s(result, strlen(str) + 1, str);
		return result;
	}

public:
	Passport() : fullName(copyString("NoInfo")),
		dateOfBirth(copyString("00.00.0000")),
		passportNumber(copyString("000000000")),
		nationality(copyString("NoInfo")),
		dateOfIssue(copyString("00.00.0000")),
		expiryDate(copyString("00.00.0000")),
		issuingAuthority(0000) {}

	Passport(const char* fullName, const char* dateOfBirth, const char* passportNumber,
		const char* nationality, const char* dateOfIssue, const char* expiryDate,
		int issuingAuthority)
	{
		cout << "\nErrors: " << endl;
		this->fullName = copyString(fullName);

		if (IsValidDateFormat(dateOfBirth))
			this->dateOfBirth = copyString(dateOfBirth);
		else
		{
			cout << "Invalid date format!" << endl;
			this->dateOfBirth = copyString("00.00.0000");
			countOfErrors++;
		}

		bool isValidPassportNumber = strlen(passportNumber) == 9;
		
		for (int i = 0; isValidPassportNumber && i < 9; i++)
		{
			if (passportNumber[i] < '0' || passportNumber[i] > '9')
				isValidPassportNumber = false;
		}

		if (isValidPassportNumber)
			this->passportNumber = copyString(passportNumber);
		else
		{
			cout << "The passport number must consist of 9 digits!" << endl;
			this->passportNumber = copyString("000000000");
			countOfErrors++;
		}

		this->nationality = copyString(nationality);

		if (IsValidDateFormat(dateOfIssue))
			this->dateOfIssue = copyString(dateOfIssue);
		else
		{
			cout << "Invalid date format!" << endl;
			this->dateOfIssue = copyString("00.00.0000");
			countOfErrors++;
		}

		if (IsValidDateFormat(expiryDate))
			this->expiryDate = copyString(expiryDate);
		else
		{
			cout << "Invalid date format!" << endl;
			this->expiryDate = copyString("00.00.0000");
			countOfErrors++;
		}

		if (issuingAuthority >= 1000 && issuingAuthority <= 9999)
			this->issuingAuthority = issuingAuthority;
		else
		{
			cout << "The issuing authority number must consist of 4 digits!" << endl;
			countOfErrors++;
			this->issuingAuthority = 0000;
		}

		if (countOfErrors > 0)
			cout << "\nCount of errors: " << countOfErrors << endl << endl;
		else
			cout << "No errors!" << endl;
	}

	Passport(const Passport& other)
		: fullName(copyString(other.fullName)), dateOfBirth(copyString(other.dateOfBirth)),
		passportNumber(copyString(other.passportNumber)), nationality(copyString(other.nationality)),
		dateOfIssue(copyString(other.dateOfIssue)), expiryDate(copyString(other.expiryDate)),
		issuingAuthority(other.issuingAuthority), countOfErrors(other.countOfErrors) {}

	Passport& operator=(const Passport& other)
	{
		if (this == &other)
			return *this;

		delete[] fullName;
		delete[] dateOfBirth;
		delete[] passportNumber;
		delete[] nationality;
		delete[] dateOfIssue;
		delete[] expiryDate;

		fullName = copyString(other.fullName);
		dateOfBirth = copyString(other.dateOfBirth);
		passportNumber = copyString(other.passportNumber);
		nationality = copyString(other.nationality);
		dateOfIssue = copyString(other.dateOfIssue);
		expiryDate = copyString(other.expiryDate);
		issuingAuthority = other.issuingAuthority;
		countOfErrors = other.countOfErrors;

		return *this;
	}

	virtual void showInfo() const
	{
		cout << "FullName: " << fullName << endl;
		cout << "Date of birth: " << dateOfBirth << endl;
		cout << "Passport number: " << passportNumber << endl;
		cout << "Nationality: " << nationality << endl;
		cout << "Date Of issue: " << dateOfIssue << endl;
		cout << "Expiry date: " << expiryDate << endl;
		cout << "Issuing authority: " << issuingAuthority << endl;
	}

	virtual ~Passport()
	{
		delete[] fullName;
		delete[] dateOfBirth;
		delete[] passportNumber;
		delete[] nationality;
		delete[] dateOfIssue;
		delete[] expiryDate;
	}
};

class ForeignPassport : public Passport
{
protected:

	char* foreignPassportNumber;
	char** visaCountries;
	int visaCount;
	bool isBiometric;
public:
	ForeignPassport() : Passport(),foreignPassportNumber(copyString("??000000")), visaCountries(nullptr), visaCount(0), isBiometric(false) {};

	ForeignPassport(const char* fullName, const char* dateOfBirth,
		const char* passportNumber, const char* nationality,
		const char* dateOfIssue, const char* expiryDate,
		int issuingAuthority, const char* foreignPassportNumber,
		const char** visaCountries, const int visaCount, bool isBiometric)
		: Passport(fullName, dateOfBirth, passportNumber, nationality,
			dateOfIssue, expiryDate, issuingAuthority),
		foreignPassportNumber(nullptr),
		visaCountries(nullptr),
		visaCount(0),
		isBiometric(isBiometric)
	{
		cout << "\nErrors: " << endl;
		
		bool isValidForeignNumber =
			foreignPassportNumber != nullptr &&
			strlen(foreignPassportNumber) == 8;

		for (int i = 0; isValidForeignNumber && i < 8; i++)
		{
			if (i < 2)
			{
				if (foreignPassportNumber[i] < 'A' ||
					foreignPassportNumber[i] > 'Z')
					isValidForeignNumber = false;
			}
			else
			{
				if (foreignPassportNumber[i] < '0' ||
					foreignPassportNumber[i] > '9')
					isValidForeignNumber = false;
			}
		}

		if (isValidForeignNumber)
			this->foreignPassportNumber = copyString(foreignPassportNumber);
		else
		{
			cout << "The passport number must consist of 2 letters and 6 digits!"
				<< endl;
			this->foreignPassportNumber = copyString("XX000000");
			countOfErrors++;
		}

		if (visaCount < 0)
		{
			cout << "The number of visas cannot be negative!" << endl;
			countOfErrors++;
		}
		else if (visaCount > 0 && visaCountries != nullptr)
		{
			this->visaCountries = new char* [visaCount];

			for (int i = 0; i < visaCount; i++)
			{
				if (visaCountries[i] != nullptr)
					this->visaCountries[i] = copyString(visaCountries[i]);
				else
					this->visaCountries[i] = copyString("NoInfo");
			}

			this->visaCount = visaCount;
		}
		else if (visaCount > 0)
		{
			cout << "Visa countries array is nullptr!" << endl;
			countOfErrors++;
		}

		if (countOfErrors > 0)
			cout << "\nCount of errors: " << countOfErrors << endl << endl;
		else
			cout << "No errors!" << endl << endl;
	
	}

	ForeignPassport(const ForeignPassport& other)
		: Passport(other),
		foreignPassportNumber(copyString(other.foreignPassportNumber)),
		visaCountries(nullptr),
		visaCount(other.visaCount),
		isBiometric(other.isBiometric)
	{
		if (other.visaCountries != nullptr && visaCount > 0)
		{
			visaCountries = new char* [visaCount];

			for (int i = 0; i < visaCount; i++)
			{
				visaCountries[i] = copyString(other.visaCountries[i]);
			}
		}
	}

	ForeignPassport& operator=(const ForeignPassport& other)
	{
		if (this == &other)
			return *this;

		Passport::operator=(other);

		delete[] foreignPassportNumber;

		if (visaCountries != nullptr)
		{
			for (int i = 0; i < visaCount; i++)
				delete[] visaCountries[i];

			delete[] visaCountries;
		}

		foreignPassportNumber = copyString(other.foreignPassportNumber);

		visaCountries = nullptr;
		visaCount = other.visaCount;
		isBiometric = other.isBiometric;

		if (other.visaCountries != nullptr && visaCount > 0)
		{
			visaCountries = new char* [visaCount];

			for (int i = 0; i < visaCount; i++)
			{
				visaCountries[i] = copyString(other.visaCountries[i]);
			}
		}

		return *this;
	}

	void showInfo()const  override
	{
		Passport::showInfo();
		cout << "Foreign passport number: " << foreignPassportNumber << endl;
		cout << "Visa countries: ";

		if (visaCountries != nullptr && visaCount > 0)
		{
			for (int i = 0; i < visaCount; i++)
			{
				cout << visaCountries[i];

				if (i < visaCount - 1)
					cout << ", ";
			}
		}
		else
		{
			cout << "No visa countries";
		}

		cout << endl;
		
		cout << "Visa count: " << visaCount << endl;
		cout << "Biometric: " << (isBiometric ? "Yes" : "No") << endl;
	}

	~ForeignPassport()
	{
		delete[] foreignPassportNumber;

		if (visaCountries != nullptr)
		{
			for (int i = 0; i < visaCount; i++)
				delete[] visaCountries[i];

			delete[] visaCountries;
		}

	}
};

int main()
{
	/*Student student("Christopher ", 20, "KNU", "Computer Science");

	Aspirant aspirant("Alex", 24, "NaUKMA", "Computer Science",
		"Artificial Intelligence",
		"Ivan Petrov",
		"2026",
		true);

	student.showInfo();

	cout << "\n===== ASPIRANT =====" << endl;
	aspirant.showInfo();

	aspirant.workOnResearch();

	Student* ptr = &aspirant;
	ptr->showInfo();

	Student* students[2] = { &student, &aspirant };

	for (int i = 0; i < 2; i++)
	{
		cout << "\n-------------------" << endl;
		students[i]->showInfo();
	}*/
	
	const char* countries[] = {
	"Germany",
	"France",
	"Poland"
	};

	Passport passport(
		"Nazar Kokhno",
		"15.05.2010",
		"123456789",
		"Ukraine",
		"01.06.2025",
		"01.06.2035",
		1234
	);

	ForeignPassport foreignPassport(
		"Alex Smith",
		"20.03.2000",
		"987654321",
		"USA",
		"01.06.2025",
		"01.06.2035",
		5678,
		"GH123456",
		countries,
		3,
		true
	);

	cout << "\n===== PASSPORT =====" << endl;
	passport.showInfo();

	cout << "\n===== FOREIGN PASSPORT =====" << endl;
	foreignPassport.showInfo();

	Passport* ptr = &foreignPassport;
	ptr->showInfo();

	Passport* passports[2] = { &passport, &foreignPassport };

	for (int i = 0; i < 2; i++)
	{
		cout << "\n-------------------" << endl;
		passports[i]->showInfo();
	}

	

	return 0;
}
