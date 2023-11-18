#include <stdio.h>
#include <curl/curl.h>

/*to get your public ip, go the https://noip.com register and generate a hostname*/
/*why do you need a host name?, your public IP cannot be seen from within your device*/
/*so you have to request it from an outside source*/
/*noip.com will get the ip and map it to a host name for you for free on their free tier*/
/* the host name will allow you use the IP to create a Local server*/
/*Note, ISP change the public IPs*/
/*thats why you need this code, to be able to update the IP if the IP has been changed*/
/*if you have issues setting up the enviroment, contact me on firmino3535@gmail.com*/

int main(void){
	CURL *curl;
	Curlcode res;

	const char* username = "put your username";
	const char* password = "put your password";
	const char* hostname = "put the hostname you selected";


	const char* api_url = "https://dynupdate.no-ip.com/nic/update";
	snprintf(url, sizeof(url), api_url, hostname);

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	if(curl){
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURL_USERPWD, curl_easy_escape(curl, username, 0));
		curl_easy_setopt(curl, CURLOPT_PASSWORD, curl_easy_escape(curl, password, 0));

		res = curl_easy_perform(curl);

		if(res == CURLE_OK){
			printf("IP address update successful.\n");
		}else{
			printf("IP address update failed. Error: %s\n", curl_easy_strerror(res));
		}

		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();

	return 0;
}