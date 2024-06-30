// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно?"), "Совсем недавно вы пытались задать мне вопрос...", "М-да, позвольте угадаю... Опять ничего существенного?",
                          "Послушайте, я финансами оперирую, а не на вопросы отвечаю...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Вы угадали, простите...", "Я понимаю...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//--> Бремя гасконца
			if (CheckAttribute(pchar, "questTemp.Sharlie.Junglejew1") && !CheckAttribute(npchar, "quest.junglejew1"))
			{
				link.l1 = "Взгляните на эти серьги, месье. Я нашёл их в кармане мёртвого бандита в джунглях. Это явно работа хорошего ювелира, которого в этой глуши и быть не могло. Можете что-нибудь сказать о них?";
                link.l1.go = "Sharlie_junglejew";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "bankskiper")
			{
				link.l1 = "Меня интересуют долговые расписки местного начальника тюрьмы.";
                link.l1.go = "Sharlie";
			}	
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "bankskipermoney")
			{
				link.l1 = "Я по поводу долга Фулька Делюка.";
                link.l1.go = "Sharlie_repeat";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "banksharlieagain")
			{
				link.l1 = "Ну что, у вас появилась информация, где искать вашего должника?";
                link.l1.go = "Sharlie_again";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "usurerblackmail")
			{
				link.l1 = "Я по поводу расписок начальника тюрьмы.";
                link.l1.go = "Sharlie_blackmail";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "bankskipercaptive")
			{
				link.l1 = "Я выполнил ваше задание, месье. Вот ваш... испанский друг.";
                link.l1.go = "Sharlie_14";
			}
			//<-- Бремя гасконца
		break;
		
		case "Sharlie":
			dialog.text = "Что вы имеете в виду? Ах...да, конечно. Он оказался в сложной ситуации, проиграв крупную сумму, и мне пришлось прийти к нему на помощь.";
			link.l1 = "Ну да...А теперь и я решил прийти к нему на помощь. Я хочу, чтобы вы уступили мне его долг. Думаю, мы оба как разумные люди понимаем, что он никогда не сможет выплатить вам требуемую сумму, и если ничего не предпринять, то он угодит за решётку собственной тюрьмы, а вы потеряете деньги. Все проиграют. Поэтому я предлагаю вам половину суммы за расписки. Если я не ошибаюсь, речь идёт о сумме долга в сто тысяч. Я готов вам выплатить пятьдесят, а вы отдадите их мне.";
			link.l1.go = "Sharlie_1";
		break;
		
		case "Sharlie_1":
			dialog.text = "А вы ловкий малый, месье. Но увы, ваше предложение мне не подойдёт. И долг, включая проценты, теперь составляет сто пятьдесят тысяч. Проценты за то, что этот мерзавец, видимо, пользуясь своими связями в тюремной среде, подослал ко мне вора, который перевернул вверх дном всю мою контору. Сомневаюсь, что он вам об этом поведал, как и многом другом. И деньги у него есть при его то должности. Так что пусть платит или я иду к губернатору.";
			link.l1 = "Значит, возможности уладить дело нет?";
			link.l1.go = "Sharlie_2";
		break;


		case "Sharlie_2":
			dialog.text = "Ну почему же? Если вы так хотите, можете заплатить мне сейчас сто пятьдесят тысяч, и я отдам вам долговые расписки.";
			link.l1 = "Я не подсылал к вам воров, поэтому не понимаю, за что должен платить 'проценты'.";
			link.l1.go = "Sharlie_3";
		break;

		case "Sharlie_3":
			dialog.text = "Я и сам не понимаю, молодой человек, зачем вы так хлопочете за этого негодяя. Деньги действительно немаленькие, но я не уступлю. Это вопрос принципа. Я никому не позволю себя обворо.... А хотя.... Вы капитан корабля? Мне нужна особая конфиденциальная услуга. Обычно, если какой-то должник упорствует и не хочет платить, я прибегаю к услугам властей. Гораздо хуже, когда должником является один из представителей этих властей. Вот как в нашем с вами случае. Но, поверьте, на него я смогу найти управу. (бормочет про себя) Чтоб я ещё дал денег этим местным солдафонам.\n Но есть случаи, когда мне нужна помощь со стороны. Речь идет о человеке, который, по моим сведениям, сейчас находится в Ле Франсуа. Я совершил очевидную глупость и выдал ему весьма крупную сумму денег. Но предприятие, которое сулило большие выгоды, а мне высокий процент, провалилось. Ближайшие дни я должен узнать, где он находится. Мне надо, чтобы вы расправились с ним и с его охраной и принесли мне все деньги и бумаги, которые будут при нём.";
			link.l1 = "Но если умрёт ваш должник, вы никогда не вернёте займ обратно. Зачем вам это?";
			link.l1.go = "Sharlie_4";
		break;

		case "Sharlie_4":
            dialog.text = "Я уже сказал, молодой человек, что в нашей профессии крайне важна репутация. И я не хочу иметь репутацию человека, которого можно безнаказанно кинуть. Не скрою, дело крайне опасное. Но и сто пятьдесят тысяч на дороге не валяются. Ну что? По рукам?";
            link.l1 = "Когда и где будет этот человек?";
            link.l1.go = "Sharlie_8";
	        link.l2 = "Нет, месье. Хватит с меня авантюр на этом острове.";
	        link.l2.go = "Sharlie_5";
        break;  

		
		
		case "Sharlie_5":
			dialog.text = "Тогда вам придётся заплатить сто пятьдесят тысяч, иначе расписки останутся у меня.";
			if (sti(pchar.money) >= 150000)
			{
				link.l1 = "Вот деньги.";
				link.l1.go = "Sharlie_6";
			}
			link.l2 = "Ну уж нет. Если не хотите принять помощь, разбирайтесь со своими делами сами.";
			if (CheckAttribute(pchar, "questTemp.Sharlie.FastStart")) link.l2.go = "Sharlie_5x";
			else link.l2.go = "Sharlie_exit2"; // Addon 2016-1 Jason пиратская линейка 1
		break;

		case "Sharlie_exit2":
			DialogExit();
			AddQuestRecord("Sharlie", "5-32");
			pchar.quest.Sharlie_skiper.win_condition.l1 = "location";
			pchar.quest.Sharlie_skiper.win_condition.l1.location = "My_Cabin_Small";
			pchar.quest.Sharlie_skiper.function = "Sharlie_SkiperTalk";
			
			pchar.questTemp.Sharlie = "none";
		break;
		
		case "Sharlie_6":
			AddMoneyToCharacter(pchar, -150000);
			dialog.text = "Я весьма удивлён вашему упорству. Впрочем, это не моё дело, ведь так, месье? Возьмите его расписки - теперь вы обладаете правом на его долг и можете требовать с него свои монеты .";
			link.l1 = "Ничего не поделаешь, иногда приходится дорого платить за грехи других людей. До свидания, "+npchar.name+"!";
			link.l1.go = "Sharlie_7";
		break;
		
		case "Sharlie_7":
			DialogExit();
			AddQuestRecord("Sharlie", "5-31");
			Log_Info("Вы получили долговые расписки");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "letter_open");
			ChangeItemDescribe("letter_open", "itmdescr_letter_open_usurer");
			pchar.questTemp.Sharlie = "freeskiper";
		break;
		
		case "Sharlie_5x": // Addon 2016-1 Jason пиратская линейка 1
			dialog.text = "Услуга? Увы, но я не нуждаюсь в ваших услугах, по крайней мере - сейчас.";
			link.l1 = "Жаль. Что же, тогда я принесу деньги за Фулька. До встречи!";
			link.l1.go = "exit";
			pchar.questTemp.Sharlie = "bankskipermoney";
		break;
		
		case "Sharlie_8":
			dialog.text = "Пока у меня нет этой информации. Как только я её получу, сразу направлю к вам посыльного. Разумеется, в ваших же интересах будет подкараулить его за пределами пиратского поселения.";
			link.l1 = "Хорошо, договорились.";
			link.l1.go = "Sharlie_exit1";
		break;


		case "Sharlie_exit1": 
        dialogexit();
		AddQuestRecord("Sharlie", "5-30");
		pchar.questTemp.Sharlie = "banksharlieagain";
		pchar.quest.Sharlie_skiper.win_condition.l1 = "location";
		pchar.quest.Sharlie_skiper.win_condition.l1.location = "My_Cabin_Small";
		pchar.quest.Sharlie_skiper.function = "Sharlie_SkiperTalk1";
        break; 

		case "Sharlie_again":
			dialog.text = "Я же сказал, как только она у меня будет, я тут же пошлю к вам человека.";
			link.l1 = "";
			link.l1.go = "exit";
		break;


		case "Sharlie_blackmail":
			dialog.text = "А что по поводу расписок? На завтра у меня запланирована аудиенция у Его Светлости, где я их ему предъявлю и подам прошение о взыскании. Если этот негодяй не вернёт мне мои деньги с компенсацией, ему грозит оказаться под собственной охраной, хе-хе.";
			link.l1 = "Но мы договаривались...";
			link.l1.go = "Sharlie_blackmail_1";
		break;

		case "Sharlie_blackmail_1":
			dialog.text = "Да, я в курсе, молодой человек. Вы получили хороший удар саблей, но я вас предупреждал о всех рисках. Мне жаль, но дело вы провалили, и я вам ничего не должен. У меня к вам лишь один вопрос: вы упомянули моё имя...там в бухте?";
			link.l1 = "А что это вы так беспокоитесь? Смею вас заверить, что опасаться вам надо не его, а меня. Если вы позволяете себе так подло поступить со мной, то я смогу вам отплатить той же монетой. Я обязательно завтра посещу вашу аудиенцию у губернатора и открою глаза Его Светлости на то, как вы ссужаете деньги заговорщикам, которые убивают на улицах его людей и похищают его жену и дочь.";
			link.l1.go = "Sharlie_blackmail_2";
		break;

		case "Sharlie_blackmail_2":
			dialog.text = "(Побледнев) Откуда...Это всё подлая ложь, у вас нет никаких доказательств, ведь вы же их не получили, как я вас просил.";
			link.l1 = "В некотором роде я помог вернуть губернатору его семью, поэтому посмотрим, кому из нас он завтра поверит, и потребуются ли ему дальнейшие доказательства.";
			link.l1.go = "Sharlie_blackmail_3";
		break;


		case "Sharlie_blackmail_3":
			dialog.text = "Ну хорошо...Я и не знал, что Его Светлость обязан вам столь многим. (резко меняя тон на подобострастный) Что ж вы сразу мне не сказали, дорогой мой. Одно ваше слово, и я отдал бы вам эти чёртовы расписки без всяких условий. Я бы никогда не стал рисковать жизнью столь ценного человека. Вот возьмите и запомните, месье, что у вас во всей колонии не сыщется большего друга, чем я...Ведь вы дорожите своими друзьями, месье де Мор?";
			link.l1 = "Конечно, и я очень рад, что мы так хорошо поладили. Но это не всё. Я хочу знать имя этого вашего бывшего должника.";
			link.l1.go = "Sharlie_blackmail_4";
		break;


		case "Sharlie_blackmail_4":
			dialog.text = "При всём к вам уважении и искреннем расположении я не могу раскрывать имена моих клиентов, даже бывших....";
			link.l1 = "Не стоит останавливаться на достигнутом, 'мой лучший друг'. Я ведь могу и передумать не посещать вашу завтрашнюю аудиенцию у губернатора.";
			link.l1.go = "Sharlie_blackmail_5";
		break;

		case "Sharlie_blackmail_5":
			dialog.text = "Ну хорошо...только для вас в виде исключения. Его зовут Грегуар Валинье, и это очень опасный человек, уверяю вас!";
			link.l1 = "(на время потеряв дар речи) Что?! Да как ты смеешь, каналья! Откуда тебе известно это имя?!";
			link.l1.go = "Sharlie_blackmail_6";
		break;


		case "Sharlie_blackmail_6":
			dialog.text = "(испуганно) Так он сам представился, месье де Мор! Он заявился с известными всей колонии подручными Барбазона и потребовал выдать ему кредит под весьма щедрые проценты. А в противном случае обещал, что они угробят мой бизнес после того...после того, как захватят Сен-Пьер. Ну что мне оставалось делать?! А потом до меня дошли слухи, что провалилась какая-то попытка захвата Мальтийской базы, вот я и решил, что мои деньги тю-тю...";
			link.l1 = "Скажи лучше, что хотел избавиться от свидетеля своего предательства, идиот! А заодно от всех доказательств. Грегуар Валинье, говоришь? Ну-ну, хе-хе. Если ещё кому-либо назовёшь это имя, я лично отрежу тебе язык. Ты уяснил?";
			link.l1.go = "Sharlie_blackmail_7";
		break;


		case "Sharlie_blackmail_7":
			dialog.text = "Да, месье де Мор. Я же говорю, что ничего не знаю.";
			link.l1 = "И будь в следующий раз осмотрительнее в выборе клиентов. Всего доброго.";
			link.l1.go = "Sharlie_blackmail_exit";
		break;

		case "Sharlie_blackmail_exit": 
        dialogexit();
		AddQuestRecord("Sharlie", "5-43");
		Log_Info("Вы получили долговые расписки");
		PlaySound("interface\important_item.wav");
		GiveItem2Character(pchar, "letter_open");
		ChangeItemDescribe("letter_open", "itmdescr_letter_open_usurer");
		pchar.questTemp.Sharlie = "freeDugari";
		break;
		
		case "Sharlie_9":
			dialog.text = "Для вашей драгоценной жизни, конечно. Так что подумайте, перед тем как дать согласие, готовы ли вы к такому.";
			link.l1 = "Сударь, мне не впервой смотреть в глаза опасностям разного рода. Так что давайте перейдем к описанию подробностей, и если для этого не нужно будет в одиночку вырезать гарнизон форта, возможно, я смогу выполнить то, о чём вы сейчас так загадочно намекаете.";
			link.l1.go = "Sharlie_10";
		break;
		
		case "Sharlie_10":
			dialog.text = "Хорошо. Тогда слушайте. Сегодня вечером из пиратского логова Ле Франсуа, что находится в восточной части нашего острова, выйдут несколько пиратов и отправятся в бухту Ле Марен. С ними будет пленник - испанский офицер, которого они собираются сдать за выкуп англичанам\nЭтот испанский офицер - замечательный специалист в фортификационном деле, и англичане намерены использовать его таланты в своих целях. За ним специально в бухту Ле Марен присылают военный корабль из Порт-Рояля\nОфицер - мой старинный знакомый, и я бы не хотел, чтобы он попал в плен к англичанам. Как вы понимаете, к официальным властям острова я обратиться не могу, поскольку мы с Испанией находимся в состоянии вражды\nБудь у меня побольше времени, я бы, конечно, нанял соответствующих людей для перехвата испанца... кхм, моего знакомого, но увы! Мне остаётся только предложить это дело вам, а именно: отправиться в бухту Ле Марен и... убедить пиратов отдать вам пленника\nНе думаю, что они окажутся сговорчивыми, так что - решайте.";
			link.l1 = "Сколько будет пиратов в конвое испанца?";
			link.l1.go = "Sharlie_11";
		break;
		
		case "Sharlie_11":
			dialog.text = "Не знаю. Может, человека два, а может - три или четыре. Ну, так что скажете?";
			link.l1 = "Я уже сказал вам - мне не привыкать смотреть в лицо опасности, и я знаю, с какой стороны держать шпагу.";
			link.l1.go = "Sharlie_10";
			link.l2 = "Хм. Вы правы - дело опасное. Не буду я в одиночку нападать на отряд пиратов.";
			link.l2.go = "Sharlie_12";
		break;
		
		case "Sharlie_12":
			dialog.text = "Дело ваше. Если чувствуете, что не по плечу ноша - то лучше сразу отказаться. Тогда жду вас с деньгами в качестве уплаты долга Делюка.";
			link.l1 = "Хорошо. Я принесу деньги за него. До встречи!";
			link.l1.go = "exit";
			pchar.questTemp.Sharlie = "bankskipermoney";
		break;
		
		case "Sharlie_13":
			dialog.text = "Очень хорошо. Рад слышать это. Тогда вам следует отправляться в бухту Ле Марен - пираты будут там приблизительно с девяти вечера и до полуночи. Не прозевайте их! И не вздумайте идти в бухту на корабле - спугнете негодяев. Только по суше через джунгли!\nКогда освободите пленника, приведёте его ко мне - дверь будет открыта даже ночью. Будьте осторожны и удачи вам!";
			link.l1 = "Спасибо! Удача мне точно понадобится...";
			if (CheckCharacterItem(pchar, "pistol1")) link.l1.go = "Sharlie_13";
			else link.l1.go = "Sharlie_14";
		break;
		
		case "Sharlie_14":
			dialog.text = "Одну минуту! Вижу, у вас нет даже пистоля. Возьмите один из моих, и несколько зарядов к нему. Думаю, это вам пригодится.";
			link.l1 = "Да, эта штучка однозначно может понадобиться. Благодарю вас, сударь.";
			link.l1.go = "Sharlie_15";
		break;
		
		case "Sharlie_15":
			Log_Info("Вы получили строевой пистоль");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "pistol1");
			TakeNItems(pchar, "bullet", 20);
			TakeNItems(pchar, "gunpowder", 20);
			dialog.text = "А теперь ступайте, и да поможет вам Бог!";
			link.l1 = "...";
			link.l1.go = "Sharlie_16";
		break;
		
		case "Sharlie_16":
			DialogExit();
			pchar.quest.Sharlie_captive.win_condition.l1 = "HardHour";
			pchar.quest.Sharlie_captive.win_condition.l1.hour = 21.00;
			pchar.quest.Sharlie_captive.function = "Captive_Timer";
			SetFunctionTimerCondition("Captive_CreatePiratesOver", 0, 0, 1, false);
			AddQuestRecord("SharlieD", "1");
			pchar.questTemp.Sharlie = "bankskiperfight";
			pchar.questTemp.Sharlie.Captive = "true";
			pchar.questTemp.Sharlie.Captive.Name = GetFullName(npchar);
			DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
		break;
		
		case "Sharlie_17":
			pchar.quest.Sharlie_captive1.over = "yes";
			pchar.quest.Sharlie_captive2.over = "yes";
			ref sld = characterFromId("CaptiveSpain");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 5.0);
			sld.lifeday = 0;
			SetNationRelation2MainCharacter(FRANCE, RELATION_FRIEND);
			DeleteAttribute(pchar, "questTemp.Sharlie.Captive");
			dialog.text = "Замечательно! Очень рад, что вам удалось успешно с этим справиться. Подробности дела, мне, пожалуй, лучше не знать, ведь так? Ну, а мой дорогой испанский гость может чувствовать себя у меня дома в безопасности...";
			link.l1 = "Что насчет долга Фулька Делюка?";
			link.l1.go = "Sharlie_18";
		break;
		
		case "Sharlie_18":
			dialog.text = "Да, конечно. Возьмите его расписки - теперь вы обладаете правом на его долг и можете требовать свои монеты с него. Ну и, конечно, ходатайствовать о его освобождении из тюрьмы. Я всё сделал, как обещал?";
			link.l1 = "Да, месье. Всё строго согласно договору. А теперь разрешите откланяться.";
			link.l1.go = "Sharlie_4";
			AddQuestRecord("SharlieD", "7");
			CloseQuestHeader("SharlieD");
			DeleteAttribute(pchar, "questTemp.Sharlie.Captive");
		break;
		
		case "Sharlie_repeat":
			dialog.text = "Итак, вы готовы заплатить за него долг?";
			if (sti(pchar.money) >= 10450)
			{
				link.l1 = "Да. Вот деньги.";
				link.l1.go = "Sharlie_3";
			}
			link.l2 = "К сожалению, я ещё не собрал нужной суммы...";
			link.l2.go = "exit";
		break;
		
		case "Sharlie_junglejew":
			dialog.text = "Хм. Похоже, вы правы - это дорогие серьги, и сделаны в Старом Свете, несомненно... Что я могу сказать? Я могу дать вам за них тридцать... нет, даже тридцать пять золотых дублонов. Соглашайтесь, дороже вам их не продать.";
			link.l1 = "Тридцать пять дублонов? Неплохая цена. Я согласен. Забирайте.";
			link.l1.go = "Sharlie_junglejew_1";
			link.l2 = "Нет. Лучше я оставлю эту драгоценность себе.";
			link.l2.go = "exit";
			npchar.quest.junglejew = "true";
		break;
		
		case "Sharlie_junglejew_1":
			DialogExit();
			PlaySound("interface\important_item.wav");
			Log_Info("Вы отдали серьги");
			RemoveItems(pchar, "jewelry25", 1);
			TakeNItems(pchar, "gold_dublon", 35);
			AddQuestRecord("SharlieE", "3");
			CloseQuestHeader("SharlieE");
			DeleteAttribute(pchar, "questTemp.Sharlie.Junglejew");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

