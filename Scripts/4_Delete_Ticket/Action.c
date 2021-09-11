Action()
{


lr_start_transaction("UC_04_Delete_ticket");
		
	MainPage();
	
		lr_think_time(5);
		
	Login();
	
		lr_think_time(5);
	
	Itinerary();
	
		lr_think_time(5);

	ChooseTicketForDelete();
		
		lr_think_time(5);
		
	SignOff();

lr_end_transaction("UC_04_Delete_ticket",LR_AUTO);

	return 0;
}