// #include "../incl/Chat.hpp"

// //NOT TESTED
// size_t WriteCallback(char *contents, size_t size, size_t nmemb, string *output)
// {
//     size_t totalSize = size * nmemb;
//     output->append(contents, totalSize);
//     return totalSize;
// }

// int aiPrompt()
// {
//     CURL *curl = curl_easy_init();

//     if (curl)
//     {
//         string apiEndpoint = "https://api.openai.com/v1/engines/davinci-codex/completions";
//         string apiKey = APIKEY;

//         struct curl_slist *headers = NULL;
//         headers = curl_slist_append(headers, ("Authorization: Bearer " + apiKey).c_str());
//         headers = curl_slist_append(headers, "Content-Type: application/json");

//         curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
//         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

//         std::string requestData = "{\"prompt\": \"Imagine you are a doctor of an important hospital and Im going to ask you some health related question. Please, stay on topic.\", \"max_tokens\": 100}";

//         curl_easy_setopt(curl, CURLOPT_URL, apiEndpoint.c_str());
//         curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestData.c_str());

//         std::string response;
//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

//         CURLcode res = curl_easy_perform(curl);
//         if (res != CURLE_OK)
//         {
//             std::cerr << "Terrible Sorry: OpenAi is down ATM. Please try again later: " << curl_easy_strerror(res) << std::endl;
//             return -1;
//         }
//         else
//         {
//             std::cout << "API response: " << response << std::endl;
//         }

//         string prompt;
//         cout << RED << "0 " << ENDC << " to go back.\n";
//         while (true)
//         {
//             cout << "Ask us anything: ";
//             getline(cin, prompt);

//             if (prompt == "0")
//             {
//                 break;
//             }
//             string requestData = "{\"prompt\": \"" + prompt + "\", \"max_tokens\": 100}";

//             curl_easy_setopt(curl, CURLOPT_URL, apiEndpoint.c_str());
//             curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestData.c_str());

//             string response;
//             curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

//             CURLcode res = curl_easy_perform(curl);
//             if (res != CURLE_OK)
//                 cerr << "Response failed: " << curl_easy_strerror(res) << endl;
//             else
//                 cout << "Doctor: " << response << std::endl;
//         }
//         curl_easy_cleanup(curl);
//         curl_slist_free_all(headers);
//     }
//     return 1;
// }
