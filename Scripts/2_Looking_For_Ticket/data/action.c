Action()
{

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("WebTours", 
		"URL=http://localhost.com:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_url("header.html", 
		"URL=http://localhost.com:1080/WebTours/header.html", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://localhost.com:1080/WebTours/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_url("welcome.pl", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/WebTours/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("looking_for_ticket");

	lr_start_transaction("login");

	web_add_header("Origin", 
		"http://localhost.com:1080");

	lr_think_time(10);

	web_submit_data("login.pl", 
		"Action=http://localhost.com:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=132085.603564196zHQtVfDpcDDDDDDDtAHztpQVQt", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=48", ENDITEM, 
		"Name=login.y", "Value=3", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(13);

	lr_start_transaction("flights");

	web_url("Search Flights Button", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("flights",LR_AUTO);

	lr_start_transaction("find_flight");

	web_add_auto_header("Origin", 
		"http://localhost.com:1080");

	web_submit_data("reservations.pl", 
		"Action=http://localhost.com:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=San Francisco", ENDITEM, 
		"Name=departDate", "Value=2/03/2021", ENDITEM, 
		"Name=arrive", "Value=Zurich", ENDITEM, 
		"Name=returnDate", "Value=09/05/2021", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=50", ENDITEM, 
		"Name=findFlights.y", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("find_flight",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("chose_ticket");

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost.com:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/reservations.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=692;355;2/03/2021", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=reserveFlights.x", "Value=30", ENDITEM, 
		"Name=reserveFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("chose_ticket",LR_AUTO);

	lr_start_transaction("sign_off");

	web_revert_auto_header("Origin");

	lr_think_time(18);

	web_url("SignOff Button", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("sign_off",LR_AUTO);

	lr_end_transaction("looking_for_ticket",LR_AUTO);

	return 0;
}