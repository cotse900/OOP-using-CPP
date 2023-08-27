/**************************************************
OOP345NFF Workshop 8
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 11 Nov 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (size_t m = 0; m < emp.size(); m++) {
			for (size_t n = 0; n < sal.size(); n++) {
				if (activeEmp.validateSIN(emp[m].id) || activeEmp.validateSIN(sal[m].id)) {
					if (emp[m].id == sal[n].id) {
						EmployeeWage* wageObject = new EmployeeWage(emp[m].name, sal[n].salary);
						try {
							wageObject->rangeValidator();
							activeEmp += wageObject;
							delete wageObject;
						}
						catch (...) {
							delete wageObject;
							throw;
						}
					}
				}
			}
		}
		
		
		return activeEmp;
	}
}