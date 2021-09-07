Action()
{

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("WebTours", 
		"URL=http://localhost.com:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_url("header.html", 
		"URL=http://localhost.com:1080/WebTours/header.html", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://localhost.com:1080/WebTours/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_url("welcome.pl", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/WebTours/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("login");

	lr_start_transaction("login_page");

	web_add_header("Origin", 
		"http://localhost.com:1080");

	lr_think_time(28);

	web_submit_data("login.pl", 
		"Action=http://localhost.com:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=132085.549777238zHQtVfAptzzzzzzHtAHztpQAci", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=75", ENDITEM, 
		"Name=login.y", "Value=9", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("login_page",LR_AUTO);

	lr_end_transaction("login",LR_AUTO);

	return 0;
}