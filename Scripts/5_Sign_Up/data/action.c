Action()
{

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("welcome.pl", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_think_time(18);

	lr_start_transaction("Sign_up");

	lr_start_transaction("Sign_up_button");

	web_url("login.pl", 
		"URL=http://localhost.com:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Sign_up_button",LR_AUTO);

	lr_start_transaction("filling_form");

	web_add_header("Origin", 
		"http://localhost.com:1080");

	lr_think_time(22);

	web_submit_data("login.pl_2", 
		"Action=http://localhost.com:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=momo", ENDITEM, 
		"Name=password", "Value=momo", ENDITEM, 
		"Name=passwordConfirm", "Value=momo", ENDITEM, 
		"Name=firstName", "Value=momof", ENDITEM, 
		"Name=lastName", "Value=momol", ENDITEM, 
		"Name=address1", "Value=Address", ENDITEM, 
		"Name=address2", "Value=City", ENDITEM, 
		"Name=register.x", "Value=59", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("filling_form",LR_AUTO);

	lr_think_time(18);

	lr_start_transaction("continue_button");

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

	lr_think_time(16);

	lr_start_transaction("sign_off");

	web_url("SignOff Button", 
		"URL=http://localhost.com:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost.com:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("sign_off",LR_AUTO);

	lr_end_transaction("Sign_up",LR_AUTO);

	return 0;
}