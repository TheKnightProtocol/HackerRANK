#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
  struct document doc;
    doc.paragraph_count = 0;
    doc.data = malloc(MAX_PARAGRAPHS * sizeof(struct paragraph));
    
    char *paragraph_start = text;
    char *paragraph_end;
    int para_idx = 0;
    
    while (*paragraph_start) {
        paragraph_end = strchr(paragraph_start, '\n');
        if (!paragraph_end) paragraph_end = paragraph_start + strlen(paragraph_start);
        
        struct paragraph para;
        para.sentence_count = 0;
        para.data = malloc(MAX_CHARACTERS * sizeof(struct sentence));
        
        char *sentence_start = paragraph_start;
        char *sentence_end;
        int sent_idx = 0;
        
        while (sentence_start < paragraph_end) {
            sentence_end = strchr(sentence_start, '.');
            if (!sentence_end || sentence_end >= paragraph_end) sentence_end = paragraph_end;
            
            struct sentence sent;
            sent.word_count = 0;
            sent.data = malloc(MAX_CHARACTERS * sizeof(struct word));
            
            char *word_start = sentence_start;
            char *word_end;
            int word_idx = 0;
            
            while (word_start < sentence_end) {
                word_end = strchr(word_start, ' ');
                if (!word_end || word_end >= sentence_end) word_end = sentence_end;
                
                int len = word_end - word_start;
                sent.data[word_idx].data = malloc((len + 1) * sizeof(char));
                strncpy(sent.data[word_idx].data, word_start, len);
                sent.data[word_idx].data[len] = '\0';
                
                word_idx++;
                sent.word_count++;
                word_start = word_end + 1;
            }
            
            para.data[sent_idx] = sent;
            sent_idx++;
            para.sentence_count++;
            sentence_start = sentence_end + 1;
        }
        
        doc.data[para_idx] = para;
        para_idx++;
        doc.paragraph_count++;
        
        if (*paragraph_end == '\0') break;
        paragraph_start = paragraph_end + 1;
    }
    
    return doc;
}
// Lines: 41



struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
   return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
  return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
   return Doc.data[k-1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
