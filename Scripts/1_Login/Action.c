Action()
{
	
lr_start_transaction("UC_01_logining");
		
	MainPage();
	
	lr_think_time(5);
	
	Login();
	
	lr_think_time(5);
	
	SignOff();	

lr_end_transaction("UC_01_logining",LR_AUTO);

	return 0;
}