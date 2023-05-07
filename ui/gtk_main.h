#ifndef GTK_MAIN_H
#define GTK_MAIN_H

#include <gtk/gtk.h>
#include "../src/ED_src.h"

//移位密码
struct ED_SUB{
    GtkWidget * sub_k_lb;
    GtkWidget * sub_k_text;
    GtkEntryBuffer * sub_k_text_buffer;
};
typedef struct ED_SUB ED_SUB;


struct ED_AFFINE{
    GtkWidget * affine_k1_lb;
    GtkWidget * affine_k1_text;
    GtkEntryBuffer * affine_k1_text_buffer;
    GtkWidget * affine_k2_lb;
    GtkWidget * affine_k2_text;
    GtkEntryBuffer * affine_k2_text_buffer;
};
typedef struct ED_AFFINE ED_AFFINE;

struct ED_DES{
    GtkWidget * DES_k_lb;
    GtkWidget * DES_k_text;
    GtkEntryBuffer * DES_k_text_buffer;
};
typedef struct ED_DES ED_DES;

struct ED_SMA{
    GtkWidget * SMA_pow_lb;
    GtkWidget * SMA_pow_text;
    GtkEntryBuffer * SMA_pow_text_buffer;
    GtkWidget * SMA_mod_lb;
    GtkWidget * SMA_mod_text;
    GtkEntryBuffer * SMA_mod_text_buffer;
};
typedef struct ED_SMA ED_SMA;

struct ED_RSA{
    GtkWidget * RSA_p_lb;
    GtkWidget * RSA_p_text;
    GtkEntryBuffer * RSA_p_text_buffer;
    GtkWidget * RSA_q_lb;
    GtkWidget * RSA_q_text;
    GtkEntryBuffer * RSA_q_text_buffer;
    GtkWidget * RSA_e_lb;
    GtkWidget * RSA_e_text;
    GtkEntryBuffer * RSA_e_text_buffer;
};
typedef struct ED_RSA ED_RSA;

struct WIDGET_CTRL
{
    //总布局
    GtkWidget *body_box;
    
    //加密方式选择
    GtkWidget * ED_choose_box;  //布局
    GtkWidget * ED_list_lb; //加解密方式选择
    GtkWidget * choose_cbb;
    GtkListStore * choose_list_store;
    GtkWidget * ED_choose_lb;   //加密或解密选择
    GtkWidget * ED_choose_cbb;
    GtkListStore * ED_choose_list_store;
    
    //信息输入
    GtkWidget * input_frame;
    GtkWidget * input_box;
    GtkWidget * input_info_box;
    GtkWidget * input_text;
    GtkTextBuffer * input_buffer;
    GtkWidget * input_scrolled_tx;

    //执行按钮
    GtkWidget * ED_btn;

    //信息输出
    GtkWidget * output_frame;
    GtkWidget * output_text;
    GtkTextBuffer * output_buffer;
    GtkWidget * output_scrolled_tx;
    
    //明文输出区
};

typedef struct WIDGET_CTRL WIDGET_CTRL;

int gtk_main(int argc, char* argv[]);

#endif