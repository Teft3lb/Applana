Action()
{
	
lr_start_transaction("UC_03_Buy_ticket");

	MainPage();

		lr_think_time(3);

	Login();
	
		lr_think_time(3);	

	Flights();

		lr_think_time(3);	

	FindFlight_rnd();	
	
		lr_think_time(3);
	
	ChooseTicket_rnd();
	
		lr_think_time(3);
		
	PaymentDetails();
	
		lr_think_time(5);
	
		
	//SignOff();

lr_end_transaction("UC_03_Buy_ticket",LR_AUTO);
	return 0;
}