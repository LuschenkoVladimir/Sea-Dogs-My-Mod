
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		
	case "First Time":
    dialog.text = "Месье, у вас не найдётся места на вашем корабле.... А-а, чёрт... Уже поздно...";
    link.l1 = "В чём дело? У вас проблемы?";
    link.l1.go = "dialog1";
    break;  	
		
		
		
	case "dialog1":
    dialog.text = "Мягко сказано, месье. Видите этих вежливых господ с ножами позади меня? Это можно назвать проблемой?";
    link.l1 = "Учитывая, что вы без шпаги, да, чёрт возьми!";
    link.l1.go = "dialog2";
    break;  		
		
		
		
	case "dialog2":
    dialog.text = "Мне очень неловко просить вас о помощи и впутывать в сои дела....";
    link.l1 = "Да, у меня много своих забот, но я не могу позволить им так просто зарезать вас у меня на глазах.";
    link.l1.go = "dialog3";
	link.l2 = "Мне очень жаль, но вы правы, у меня слишком много своих забот. Желаю удачи, месье.";
	link.l2.go = "dialogexit";
    break;  	



	case "dialog3":
    dialog.text = "Неужели провидение наконец-то на моей стороне?";
    link.l1 = "Встаньте за мою спину, я сам поговорю с этими господами.";
    link.l1.go = "dialogexit1";
    break; 



    case "dialogexit":
    AddDialogExitQuest("BasterEvent_4");
	dialogexit();
    break; 


    case "dialogexit1":
    AddDialogExitQuest("BasterEvent_7");
	dialogexit();
    break; 	
			
		
	

    case "AfterVictory_1":
    dialog.text = "Месье, как вас зовут? Я обязан вам жизнью!";
    link.l1 = "Шарль де Мор к вашим услугам.";
    link.l1.go = "AfterVictory_2";
    break;


    case "AfterVictory_2":
    dialog.text = "Моё имя Франсуа Сейн. До последнего времени я был.... Впрочем, боюсь, вы и так подвергаете себя большому риску, спасая меня, поэтому оставим это...";
    link.l1 = "Как вы уже убедились, я не из робкого десятка, так что продолжайте.";
    link.l1.go = "AfterVictory_3";
    break;


    case "AfterVictory_3":
    dialog.text = "Мне почему-то кажется, что вы недавно в наших краях, месье де Мор?";
    link.l1 = "Вы правы, я прибыл на Антильские острова несколько дней назад.";
    link.l1.go = "AfterVictory_4";
    break;

    
    case "AfterVictory_4":
    dialog.text = "Речь идёт об очень ценных для меня бумагах, которые у меня похитили, а теперь ещё и пытались меня убить. Это деловая переписка. Если она попадёт в руки врагов, то пострадаю не только я....А знаете, может действительно ещё не всё потряно. Глядя на то, как вы легко разделались с этими бандитами и учитывая, что теперь они захотят отомстить вам.... Хотите заработать пятьдесят тысяч?";
    link.l1 = "Всё очень туманно. Похоже вы юлите, месье Сейн. Мне казалось, что учитывая обстоятельства, я мог бы рассчитывать на большую откровенность с вашей стороны.";
    link.l1.go = "AfterVictory_5";
    break;


    
    case "AfterVictory_5":
    dialog.text = "Поверьте, на то есть серьёзные причины. Для вас действительно лучше будет не знать всей правды. А вот разделаться с этими ублюдками, которых на меня натравили, теперь и в ваших интересах. Семьдесят тысяч, месье де Мор. С вами как со своим спасителем я постараюсь быть если не максимально откровенным, то максимально щедрым.";
    link.l1 = "Что ж.....видимо, я создан для того, чтобы ввязываться во всё новые авантюры. Если надо разделаться с этими ублюдками, то я согласен.";
    link.l1.go = "AfterVictory_7";
    link.l2 = "Нет уж увольте, месье Слейн. Не хочу играть в чужие игры, да ещё вслепую.";
	link.l2.go = "AfterVictory_6";
    break;


    case "AfterVictory_6":
    AddMoneyToCharacter(pchar, 20000);
    AddDialogExitQuest("BasterEvent_101");
    dialog.text = "Я вас прекрасно понимаю. Тем не менее, я вам безмерно благодарен за своё спасение, я ваш должник. Возьмите это скромное вознаграждение.";
    link.l1 = "Всего доброго и не попадайте больше в безвыходные ситуации";
    link.l1.go = "AfterVictory_exit";
    break;


    case "AfterVictory_exit":
    NextDiag.CurrentNode = "Second Time";
	dialogexit();
    break;



    case "Second Time":
    dialog.text = "Спасибо за спасение. Я ваш должник.";
    link.l1 = "Не попадайте больше в такие ситуации.";
    link.l1.go = "AfterVictory_exit";
    break;



    case "AfterVictory_7":
    dialog.text = "Они часто проводят время в местной таверне, поэтому корчмарь наверняка что-то слышал, что-то знает. Припугните или заинтересуйте его. Большим, увы, я помочь вам не смогу.";
    link.l1 = "Да, негусто. Но вы правильно заметили, теперь мне и самому интересно покончить с этой шайкой.";
    link.l1.go = "AfterVictory_8";
    break;

    case "AfterVictory_8":
    AddDialogExitQuest("BasterEvent_10");
    
    dialog.text = "Будьте осторожны. Мне действительно жаль, что всё, что я могу вам предложить за вашу доброту, это только деньги.";
    link.l1 = "Надеюсь, я не пожалею, что связался с вами, месье. Ждите меня с хорошими новостями.";
    link.l1.go = "AfterVictory_exit1";
    break;


    case "AfterVictory_exit1":
    NextDiag.CurrentNode = "Second Time2";
	dialogexit();
    
    break;



    case "Second Time2":
    dialog.text = "У вас есть новости для меня?";
    link.l1 = "Нет, пока ищу ублюдков.";
    link.l1.go = "AfterVictory_exit1";
    break;


    case "GetDocuments":
    dialog.text = "У вас есть новости для меня?";
    link.l1 = "Да, я достал ваши документы. Хотя теперь у меня есть сомнения насчёт их принадлежности.";
    link.l1.go = "GetDocuments_1";
    break;


    case "GetDocuments_1":
    dialog.text = "Месье де Мор, у нас ведь с вами с самого начала был уговор, что в оплату за своё спасение я предлагаю вам свою щедрость, а не свою откровенность.";
    link.l1 = "Да, ваша правда.";
    link.l1.go = "GetDocuments_2";
    break;


    case "GetDocuments_2":
    dialog.text = "У меня лишь ещё один вопрос, кто заказчик и где он?";
    link.l1 = "Я хочу вам напомнить, месье Сейн, что согласно нашему уговору я возвращаю вам бумаги, а моя откровенность....";
    link.l1.go = "GetDocuments_3";
    break;


    case "GetDocuments_3":
    dialog.text = "Я вас понял. Рано или поздно я об этом узнаю сам, но предпочёл бы услышать это от вас. Давайте увеличим сумму вознаграждения до ста тысяч.";
    link.l1 = "Вы играете на моей жадности. Впрочем, не вижу причин, по которым я не могу пойти вам навстречу.";
    link.l1.go = "GetDocuments_4";
    break;


    case "GetDocuments_4":
    dialog.text = "Тогда встретимся завтра на местном маяке. Я подготовлю деньги, и там нам никто не помешает всё сделать без лишних ушей и глаз.";
    link.l1 = "Что ж, тогда до завтра.";
    link.l1.go = "GetDocuments_exit";
    break;


    case "GetDocuments_exit":
    AddDialogExitQuest("BasterEvent_48");
	dialogexit();
    break;


    case "GetDocuments_5":
    dialog.text = "Рад приветствовать вас, месье де Мор. Документы при вас?";
    link.l1 = "Точно так же как и интересующие вас сведения.";
    link.l1.go = "GetDocuments_6";
    break;


    case "GetDocuments_6":
    TakeItemFromCharacter(pchar, "SeinDocument");
	AddMoneyToCharacter(pchar, 100000);
    dialog.text = "Тогда извольте получить, как договаривались. Здесь ровно сто тысяч.";
    link.l1 = "Да, вы держите слово быть щедрым, месье. Тогда мне не остаётся ничего иного, как сдержать своё быть с вами откровенным. Если бы я знал, о чём идёт речь, едва ли я стал бы помогать вам при первой нашей встрече. Но прошлого не вернуть. Похоже, теперь меня могут разыскивать весьма влиятельные в Бастере персоны. Впрочем, за исключением Андрэ Рэно. Он оказался несговорчивым и захотел проткнуть меня шпагой. Это было роковое для него решение.";
    link.l1.go = "GetDocuments_7";
    break;


    case "GetDocuments_7":
    dialog.text = "Признаться, я так и думал. И хотя вы сожалеете о сделанном выборе, я весьма рад, что вы в столь нужный момент оказались на моей стороне. Скорее всего, завтра я навсегда покину Гваделупу, вам же мне остаётся пожелать удачи. Надеюсь эти деньги хотя бы в малой степени будут ей способствовать. Прощайте.";
    link.l1 = "Постараюсь воспользоваться этими деньгами с пользой для себя. Доброго пути.";
    link.l1.go = "GetDocuments_exit1";
    break;


    case "GetDocuments_exit1":
    AddDialogExitQuest("BasterEvent_50");
	dialogexit();
    break;


    case "GetDocuments_10":
    dialog.text = "Что вам угодно месье? И снимите маску, я предпочитаю общаться ...";
    link.l1 = "Документы! Документы, которые вам принёс молодой человек.";
    link.l1.go = "GetDocuments_11";
    break;


    case "GetDocuments_11":
    dialog.text = "Вот оно что. Кто вы?";
    link.l1 = "Этого вы не узнаете. Документы немедленно, и останетесь живы. Вы, кажется, ожидаете корабль? Вам никто не помешает уплыть с острова.";
    link.l1.go = "GetDocuments_12";
    break;


    case "GetDocuments_12":
    dialog.text = "Не слишком ли много вы на себя берёте? Вы одни, а нас трое. К бою!";
    link.l1 = "Это вам не поможет. Я давал вам шанс.";
    link.l1.go = "GetDocuments_exit2";
    break;


    case "GetDocuments_exit2":
    AddDialogExitQuest("BasterEvent_53");
	dialogexit();
    break;

	
	
	
	case "complete":
    dialog.text = "Капитан, вы уже выполнили мою просьбу?";
    link.l1 = "Господин, о котором вы мне говорили, напал на меня. Мне пришлось защищаться. На его трупе я нашёл алмаз. Держите, мне он не нужен.";
    link.l1.go = "complete1";
    break;
	
	
	
	case "complete1":
	AddQuestRecord("MyQuest", "4");
	CloseQuestHeader("MyQuest");
	log_info("вы отдали алмаз");
	TakeItemFromCharacter(pchar, "jewelry2");
	AddMoneyToCharacter(pchar, 10000);
    dialog.text = "Да, я вас понял. Стечение обстоятельств и только, хе-хе. Возьму этот камень на память. Но я не могу его взять просто так, вот ваша компенсация.";
    link.l1 = "Не знаешь, где найдёшь, а где потеряешь. Всего доброго.";
    link.l1.go = "exitcomplete";
    break;
	
	
	
	case "exitcomplete":
	NextDiag.CurrentNode = "Three Time";
	dialogexit();
    break;
	
	
	case "Three Time":
    dialog.text = "Здравствуйте, сударь. Мы разве знакомы?";
    link.l1 = "Нет, просто хотел выразить вам своё почтение.";
    link.l1.go = "exitcomplete";
    break;





	
		
		}
}