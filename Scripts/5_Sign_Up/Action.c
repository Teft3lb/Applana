Action()
{

lr_start_transaction("UC_05_Sign_up");
	
	MainPage();

		lr_think_time(5);		
	
	FillingForm();
	
		lr_think_time(5);

	ContinueButton();

		lr_think_time(5);
		
	SignOff();
	
	
	MainPage();		
		
	
lr_end_transaction("UC_05_Sign_up",LR_AUTO);

	return 0;
}