#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct station {
	char name[256];
	char rapid;
	struct station *next;
};



struct station *addstation(struct station *stop, struct station *newSt, char *query_name) {

	int zengo = 0, flag = 0; //最初か否か
	struct station *first;

	first = stop;

	printf("追加する場所は？ 最初の駅より前：1,最初の駅以降 : 0\n");
	scanf("%d", &zengo);

	if (zengo == 0) {
		printf("どの駅の次に入れますか? ");
		scanf("%s", query_name);
	}
	else if (zengo == 1) {
		printf("最初の駅の前に入れます。\n");
		query_name = first->name;
	}

	printf("駅名は？ ");
	scanf("%s%*c", newSt->name);
	printf("快速は止まりますか? ");
	scanf("%c", &newSt->rapid);

	while (stop != NULL) {

		if (strcmp(stop->name, query_name) == 0) {//一致したらどうするか
			if (zengo == 0) {
				printf("stopの次がnewStに,newStの次が元のstopのnextになっているかの確認\n");
				printf("before\n");
				printf("stop : %p, stop->next : %p\n", stop, stop->next);

				newSt->next = stop->next;//新しく入れるnewStの次の場所をstopの次の場所に指定
				stop->next = newSt;//stopの次の場所をnewStに指定

				printf("after\n");
				printf("newSt->next : %p, stop->next : %p, newSt : %p\n", newSt->next, stop->next, newSt);

				return first;

			}
			else if (zengo == 1) {
				newSt->next = first;//新しく入れるnewStの次の場所をstopに指定

				printf("しっかりnewStの次がstopになっているかの確認\n");
				printf("newSt->next : %p, stop : %p\n", newSt->next, stop);
				return newSt;//新しく入れた場所を最初の値として返す.
			}
			flag = 1;
			break;
		}
		stop = stop->next;//stopを次の駅にすすめる。
	}

	if (flag == 0) {
		printf("%sという駅は無いので追加できません。\n", query_name);
		free(newSt);
		exit(1);
	}
	return first;

}


struct station *deletestation(struct station *stop, struct station *newSt, char *query_name, int df) {

	struct station *first, *save;
	int zengo = 0, i = 0;
	int flag = 0;
	first = stop;

	printf("最初の駅を削除しますか？yes:1,no:0");
	scanf("%d", &zengo);

	if (zengo == 0) {
		printf("削除する駅を入れて: ");//削除する駅名を入れる
		scanf("%s", query_name);
	}
	else if (zengo == 1) {
		if (newSt == NULL) {
			printf("最初の駅を消します(hachioji)\n");
			return first->next;
		}
		else {
			printf("最初の駅を消します\n");
			strcpy(query_name, newSt->name);
		}
	}

	printf("while入ります");
	if (newSt == NULL) {
		stop = first;
	}
	while (stop != NULL) {
		if (strcmp(stop->name, query_name) != 0) {//一致しなければ続ける
			save = stop;
			printf("%d回目saveにstop入りました。\n", i);
			//今停車している駅の情報をsaveに一時保管
		}
		else {//名前が一致した場合
			flag = 1;
			break;//ループを抜ける--> saveの中には，1つ前の駅の情報が入っている
		}
		i++;
		stop = stop->next;//stopを次の駅にすすめる.
	}

	if (flag == 0) {
		printf("%sという駅は無いので削除できません。\n", query_name);
		exit(1);
	}

	if (zengo == 0) {
		save->next = stop->next;//１つ前の駅(save)の次の駅を今の駅(stop)の次の駅につなぎ変え、stopを飛ばす。
		if (stop->next == NULL) {
			save->next = NULL;
		}
		return first;
	}
	else if (zengo == 1) {
		if (df = 1) {
			return  newSt->next;//最初にhachiojiを消そうとする場合はstopがhachiojiで止まるため、次の駅であるstop->nextを戻り値にする
		}
		else {
			return first->next;//新しく追加した最初(newSt)の次を最初(stop)の戻り値指定にする
		}
	}

}

void showstation(struct station *start, int count) {


	while (start != NULL) {
		printf("st%d = %s\n", count, start->name);
		if (start->rapid == 'y') {
			printf("快速止まります\n");
		}
		else if (start->rapid == 'n') {
			printf("快速止まりません\n");
		}
		start = start->next;
		count++;
	}
}

struct station *readstation(FILE *fp) {

	int i = 0;

	char *filename;
	struct station *hozon, buf, *stop, *start;

	filename = "data.csv";
	fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("%sが存在しません。終了します。", filename);
		exit(1);
	}

	hozon = (struct station *)malloc(sizeof(struct station));
	start = hozon;
	stop = hozon;
	fscanf(fp, "%[^,],%c%*c", hozon->name, &hozon->rapid);

	while ((fscanf(fp, "%[^,],%c%*c", buf.name, &buf.rapid)) != EOF) {
		hozon = (struct station *)malloc(sizeof(struct station));
		*hozon = buf;
		stop->next = hozon;
		stop = hozon;
	}
	stop->next = NULL;

	stop = start;
	while (stop != NULL) {
		printf("name = %s,rapid = %c\n", stop->name, stop->rapid);
		stop = stop->next;
	}

	fclose(fp);

	return start;
	free(hozon);
}


void writestation(FILE *fp, struct station *stop) {
	int i = 0;
	char *filename;

	filename = "data.csv";
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("%sが存在しません。終了します。", filename);
		exit(1);
	}

	while (stop != NULL) {
		fprintf(fp, "%s,%c\n", stop->name, stop->rapid);
		printf("%d回目書き込み終了\n", i);
		stop = stop->next;
		i++;
	}
	fclose(fp);
}


int main() {
	int count = 0, i = 0, df = 0;

	//df:delete stationの時に使う判定用の変数。newStが絡んでくる場合、1ならnewStがまだ全ては削除されていないため先頭がnewStの中にある,0なら先頭はst[0]かそれ以降になっている

	char query_name[100] = "";
	struct station *st[10], *newSt, *stop, *start, *hozon[10];
	FILE *fp;

	hozon[0] = readstation(fp);

	st[0] = (struct station *)malloc(sizeof(struct station));
	st[0] = hozon[0];

	newSt = NULL;
	start = st[0];
	stop = start;

	while (1) {

		int a;
		printf("1:addstation, 2:deletestation, 3:showstation, 4:quit\n");
		scanf("%d", &a);
		switch (a) {
		case 1:
			stop = start;
			newSt = (struct station *)malloc(sizeof(struct station));
			start = addstation(stop, newSt, query_name);//newStが戻り値となればいい。 普通はst[0];
			break;
		case 2:
			stop = start;
			if (start == newSt) {
				df = 1;
			}
			start = deletestation(stop, newSt, query_name, df);
			//newSt->nextが戻り値となればいい
			break;
		case 3:
			stop = start;
			showstation(stop, count);
			break;
		case 4:
		default:
			stop = start;
			writestation(fp, stop);
			free(newSt);
			return 0;
		}
	}

}

