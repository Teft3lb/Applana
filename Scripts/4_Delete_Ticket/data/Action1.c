Action1()
{

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("welcome.pl", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/WebTours/", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("Delete_ticket");

	lr_start_transaction("login");

	web_add_header("Origin", 
		"http://localhost.com:1080");

	lr_think_time(20);

	web_submit_data("login.pl", 
		"Action=http://localhost.com:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=132093.646982584zHQtfzzpQzzzzzzHtAHzHptAVi", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=33", ENDITEM, 
		"Name=login.y", "Value=14", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(11);

	lr_start_transaction("Itinerary");

	web_url("Itinerary Button", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Itinerary",LR_AUTO);

	lr_start_transaction("checkbox_checked");

	web_add_header("Origin", 
		"http://localhost.com:1080");

	lr_think_time(17);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost.com:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=6050-796-JB", ENDITEM, 
		"Name=flightID", "Value=210311124-1565-jb", ENDITEM, 
		"Name=removeFlights.x", "Value=62", ENDITEM, 
		"Name=removeFlights.y", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		LAST);

	lr_end_transaction("checkbox_checked",LR_AUTO);

	lr_think_time(11);

	lr_start_transaction("sign_off");

	web_url("SignOff Button", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("sign_off",LR_AUTO);

	lr_end_transaction("Delete_ticket",LR_AUTO);

	return 0;
}