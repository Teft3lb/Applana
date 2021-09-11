Action()
{

lr_start_transaction("UC_05_Sign_up");
	
	MainPage();

		lr_think_time(12.41);		
	
	FillingForm();
	
		lr_think_time(12.41);

	ContinueButton();

		lr_think_time(12.41);
		
	SignOff();
	
	
	MainPage();		
		
	
lr_end_transaction("UC_05_Sign_up",LR_AUTO);

	return 0;
}