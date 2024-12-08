#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main()
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init(); // Khởi tạo cURL
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");                   // Đặt URL
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);                              // Cho phép chuyển hướng
        curl_easy_setopt(curl, CURLOPT_CAINFO, "D:/Project_Call_API_Google/cacert.pem"); // Đặt file CA certificate
        res = curl_easy_perform(curl);                                                   // Thực hiện request
        if (res != CURLE_OK)
        {
            fprintf(stderr, "cURL failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            printf("cURL is working correctly!\n");
        }

        curl_easy_cleanup(curl); // Dọn dẹp
    }
    else
    {
        printf("Failed to initialize cURL.\n");
    }
    system("pause"); // Dừng lại cho đến khi nhấn phím bất kỳ (Windows)

    return 0;
}
