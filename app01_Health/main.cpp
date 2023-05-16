#include "TestingApiChatGpt.hpp"
#include <curl/curl.h>

#include "Hospital.hpp"


//if av = patient, init patient
//admin = hospital (password under git ignore.GNL to recieve PASSWORD="underground"
//doctor = Name && ID

int main(int ac, char **av)
{
	Hospital	*hospital = new Hospital();

	hospital->addPatient("Miguel");


	Doctor		*dc = new Doctor("Booby", hospital);


	hospital->printPatients();
	hospital->printDoctors();


  Appointment *app = new Appointment(dc,new Patient("ass"));

	delete hospital;
	cout << GREEN << "FINITO\n";
	return 1;
}








/*
int mainFORLATER() {
  CURL *curl;
  CURLcode res;

  // Initialize the cURL session
  curl = curl_easy_init();
  if (curl) {
    // Set the API endpoint URL
    const char *url = "https://api.openai.com/v1/engines/text-davinci-003/completions";

    // Set the request payload
    const char *payload = "{\"model\":\"text-davinci-003\",\"prompt\":\"Make a list of astronomical observatories:\"}";

    // Set the request headers
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "Authorization: Bearer YOUR_API_KEY");

    // Set the cURL options
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // Perform the request
    res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK)
      std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;

    // Cleanup
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
  }

  return 0;
}
*/
