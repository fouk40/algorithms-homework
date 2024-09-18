#include <iostream>
#include <cmath>
using namespace std;


int main() {
      double property_tax, tax_increase;
      int roof_meters, roofless_meters, garden_meters, material_type, basic_services_availability, basic_services_tax, floors_number;
      
      cout << "How many square meters do you have with a roof? ";
      cin >> roof_meters;

      cout << "How many roofless square meters do you have? ";
      cin >> roofless_meters;

      cout << "How many garden meters do you have? ";
      cin >> garden_meters;

      cout << "What type of material is your building made of?" << endl;
      cout << "\t0 - high quality;" << endl;
      cout << "\t1 - adobe;" << endl ;
      cout << "\t2 - other." << endl;
      cin >> material_type;

      switch (material_type) {
            case 0:
                  tax_increase = 1.15;
                  break;
            case 1:
                  tax_increase = 1.10;
                  break;
            case 2:
                  tax_increase = 1.05;
                  break;
      }

      cout << "Are basic services (water and swewerage) available?" << endl;
      cout << "\t0 - no;" << endl;
      cout << "\t1 - yes;" << endl;
      cin >> basic_services_availability;

      switch (basic_services_availability) {
            case 0:
                  basic_services_tax = 0;
                  break;
            case 1:
                  basic_services_tax = 2500;
                  break;
      }

      cout << "How many floors are there in your building? ";
      cin >> floors_number;

      if (floors_number > 1) {
            if (floors_number == 2) {
                  tax_increase *= 1.1;
            } else if (floors_number == 3 || floors_number == 4) {
                  tax_increase *= 1.15;
            } else {
                  tax_increase *= 1.2;
            }
      }

      property_tax = (5000 * roof_meters + 3000 * roofless_meters) * tax_increase + 1000 * garden_meters + basic_services_tax;
      cout << "Your property tax is " << property_tax << " rubles." << endl;

      return 0;
}