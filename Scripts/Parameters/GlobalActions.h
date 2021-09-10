

///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here main page action. Contains "Main_page" Transaction.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////
MainPage()
{
	
	lr_start_transaction("Main_page");
	
	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

/*Correlation comment - Do not change!  Original value='132093.646982584zHQtfzzpQzzzzzzHtAHzHptAVi' Name ='userSession' Type ='ResponseBased'*/
//	web_reg_save_param_attrib(
//		"ParamName=userSession",
//		"TagName=input",
//		"Extract=value",
//		"Name=userSession",
//		"Type=hidden",
//		SEARCH_FILTERS,
//		"IgnoreRedirections=No",
//		"RequestUrl=*/nav.pl*",
//		LAST);



	web_reg_save_param("userSession",
		"LB/IC=name=\"userSession\" value=\"",
		"RB/IC=\"/>",
		LAST);

	web_reg_find("Text/IC=Web Tours",
		LAST);

	web_url("welcome.pl", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/WebTours/", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	lr_end_transaction("Main_page",LR_AUTO);
}


///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here Filling form action. Contains "filling_form" Transaction.
////////////////		Use "username", "password", "firstname", "lastname", "address1"
////////////////		and "address2" variables to correlate.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////

FillingForm()
{
	lr_start_transaction("filling_form");

	web_add_header("Origin", 
		"http://localhost.com:1080");

	web_reg_find("Text/IC=First time registering",
		LAST);


	web_url("login.pl", 
		"URL=http://localhost.com:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/WebTours/home.html", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("login.pl_2", 
		"Action=http://localhost.com:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={username}{rand}", ENDITEM, 
		"Name=password", "Value={rand}", ENDITEM, 
		"Name=passwordConfirm", "Value={rand}", ENDITEM, 
		"Name=firstName", "Value={firstname}{rand}", ENDITEM, 
		"Name=lastName", "Value={lastname}{rand}", ENDITEM, 
		"Name=address1", "Value={address1}{rand}", ENDITEM, 
		"Name=address2", "Value={address2}{rand}", ENDITEM, 
		"Name=register.x", "Value=59", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("filling_form",LR_AUTO);


}

///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here Continue button action. Contains "continue_button" Transaction.
////////////////		Use this script for confirm registration.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////

ContinueButton()
{


	lr_start_transaction("continue_button");

	web_reg_find("Text/IC=Don't forget to sign of",
		LAST);

	web_url("button_next.gif", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("continue_button",LR_AUTO);


}


///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here login action. Contains "Login" Transaction.
////////////////		Use "userSession" corelation parametry from "MainPage" function.
////////////////		Also use "username" and "password" for correlation.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////

Login()
{
	lr_start_transaction("login");

	web_add_header("Origin", 
		"http://localhost.com:1080");
	
	web_reg_find("Text/IC=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost.com:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost.com:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t40.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={username}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=33", ENDITEM,
		"Name=login.y", "Value=14", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);
	
}



///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here Itinerary page. Contains "Itinerary" transaction.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////

Itinerary()
{

	lr_start_transaction("Itinerary");

	web_reg_find("Text/IC=Flights List",
		LAST);

	web_reg_save_param("flightID",
		"LB/IC= name=\"flightID\" value=\"",
		"RB/IC=\"",
		LAST);


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
	
	
}


///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here Itinerary page with checkbox action. Contains "ChooseTicketForDelete" Transaction.
////////////////		Deleting 1 ticket.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////


ChooseTicketForDelete()
{
	
	lr_start_transaction("ChooseTicketForDelete");

	web_reg_find("Text/IC=Flights List",
		LAST);

	web_add_header("Origin", 
		"http://localhost.com:1080");


	web_submit_form("itinerary.pl", 
		"Snapshot=t37.inf", 
		ITEMDATA, 
		"Name=2", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=52",ENDITEM,
		"Name=removeFlights.y", "Value=9",ENDITEM,
		LAST);

	web_reg_find("Fail=Found",
		"Text={flightID}",
		LAST);

	lr_end_transaction("ChooseTicketForDelete",LR_AUTO);
}


///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here Flights page action. Contains "flights" Transaction.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////


Flights()
{

	lr_start_transaction("flights");

	web_reg_find("Text/IC=Flight Selections",
		LAST);

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
	
}


///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here Find flight page action. Contains "find_flight" Transaction.
////////////////		Parsing "outboundFlight" parameter.
////////////////		Use "depart", "arrive", "Date" and "Date2" variables to correlate action.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////

FindFlight()
{

	lr_start_transaction("find_flight");

	web_add_auto_header("Origin",
		"http://localhost.com:1080");

	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_reg_find("Text/IC=<B>{depart}</B> to <B>{arrive}</B>", LAST);

	web_submit_data("reservations.pl",
		"Action=http://localhost.com:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost.com:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t10.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={depart}", ENDITEM,
		"Name=departDate", "Value={Date1}", ENDITEM,
		"Name=arrive", "Value={arrive}", ENDITEM,
		"Name=returnDate", "Value={Date2}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=findFlights.x", "Value=67", ENDITEM,
		"Name=findFlights.y", "Value=8", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		LAST);

	lr_end_transaction("find_flight", LR_AUTO);
}




///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here Find flight page action. Contains "find_flight" Transaction.
////////////////		Parsing "outboundFlight_rnd" parameter.
////////////////		Use "depart", "arrive", "Date" and "Date2" variables to correlate action.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////


FindFlight_rnd()
{	

	lr_start_transaction("find_flight");

	web_add_auto_header("Origin", 
		"http://localhost.com:1080");
	
	web_reg_find("Text/IC=Flight Selections",
		LAST);

	
/*Correlation comment - Do not change!  Original value='401;312;09/01/2021' Name ='outboundFlight' Type ='ResponseBased'*/
	
	web_reg_save_param("outboundFlight",
	                   "LB/IC=outboundFlight\" value=\"",
	                   "RB/IC=\"",
	                   "Ord=ALL",
	                   LAST);


	web_submit_data("reservations.pl", 
		"Action=http://localhost.com:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t57.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={Date1}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={Date2}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=42", ENDITEM, 
		"Name=findFlights.y", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);
	                   

	lr_save_string(lr_paramarr_random("outboundFlight"),"outboundFlight_rnd");
	
	lr_end_transaction("find_flight",LR_AUTO);
}


///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here Choose Ticket page. Contains "choose_ticket" transaction.
////////////////		Use "outboundFlight" to correlate.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////

ChooseTicket()
{
	lr_start_transaction("choose_ticket");

	web_reg_find("Text/IC=Flight Reservation",
		LAST);

	web_submit_data("reservations.pl_2",
		"Action=http://localhost.com:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost.com:1080/cgi-bin/reservations.pl",
		"Snapshot=t7.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value=Coach", ENDITEM,
		"Name=seatPref", "Value=Window", ENDITEM,
		"Name=reserveFlights.x", "Value=30", ENDITEM,
		"Name=reserveFlights.y", "Value=11", ENDITEM,
		LAST);

	lr_end_transaction("choose_ticket", LR_AUTO);
}

///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here Choose Ticket page. Contains "choose_ticket" transaction.
////////////////		Use "outboundFlight_rnd" to correlate.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////

ChooseTicket_rnd()
{
	lr_start_transaction("choose_ticket");

	web_reg_find("Text/IC=Flight Reservation",
		LAST);

	web_submit_data("reservations.pl_2",
		"Action=http://localhost.com:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost.com:1080/cgi-bin/reservations.pl",
		"Snapshot=t7.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight_rnd}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value=Coach", ENDITEM,
		"Name=seatPref", "Value=Window", ENDITEM,
		"Name=reserveFlights.x", "Value=30", ENDITEM,
		"Name=reserveFlights.y", "Value=11", ENDITEM,
		LAST);

	lr_end_transaction("choose_ticket",LR_AUTO);
}

///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here Payment details action. Contains "payment_details" Transaction.
////////////////		Use "firstname", "lastname", "address1", "address2", "creditcart",
////////////////		"expdate" and "outbandFlight_rnd" to correlate.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////



PaymentDetails()
{

	lr_start_transaction("payment_details");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost.com:1080");

	web_reg_find("Text/IC=Reservation Made!",
		LAST);

	web_submit_data("reservations.pl_3",
		"Action=http://localhost.com:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost.com:1080/cgi-bin/reservations.pl",
		"Snapshot=t59.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={firstname}", ENDITEM,
		"Name=lastName", "Value={lastname}", ENDITEM,
		"Name=address1", "Value={address1}", ENDITEM,
		"Name=address2", "Value={address2}", ENDITEM,
		"Name=pass1", "Value={firstname} {lastname}", ENDITEM,
		"Name=creditCard", "Value={creditcard}", ENDITEM,
		"Name=expDate", "Value={expdate}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value=Coach", ENDITEM,
		"Name=seatPref", "Value=None", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight_rnd}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=35", ENDITEM,
		"Name=buyFlights.y", "Value=9", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);

	lr_end_transaction("payment_details",LR_AUTO);

}


///////////////////////////////////////////////////////////////////////////////////////////
////////////////
////////////////		Here sign off action. Contains "sign_off" Transaction.
////////////////
///////////////////////////////////////////////////////////////////////////////////////////

SignOff()
{
	lr_start_transaction("sign_off");

	web_reg_find("Text/IC=Web Tours",
		LAST);

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
}

