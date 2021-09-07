Action()
{

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("welcome.pl", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/WebTours/", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_header("Origin", 
		"http://localhost.com:1080");

	web_submit_form("login.pl", 
		"Snapshot=t45.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t46.inf", 
		LAST);

	lr_start_transaction("check");

	web_add_header("Origin", 
		"http://localhost.com:1080");

	lr_think_time(9);

	web_submit_form("itinerary.pl", 
		"Snapshot=t47.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=2", "Value=<OFF>", ENDITEM, 
		"Name=3", "Value=<OFF>", ENDITEM, 
		"Name=4", "Value=<OFF>", ENDITEM, 
		"Name=5", "Value=<OFF>", ENDITEM, 
		LAST);

	lr_end_transaction("check",LR_AUTO);

	return 0;
}