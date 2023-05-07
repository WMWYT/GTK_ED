#include "gtk_main.h"
#include <string.h>

WIDGET_CTRL w_ctl;
ED_SUB sub_init;
ED_AFFINE affine_init;
ED_DES des_init;
ED_SMA sma_init;
ED_RSA rsa_init;

void ED_sub_info_init(){
  sub_init.sub_k_lb = gtk_label_new("密钥:");
  sub_init.sub_k_text = gtk_entry_new();
  sub_init.sub_k_text_buffer = gtk_entry_get_buffer(GTK_ENTRY(sub_init.sub_k_text));
}

void ED_affine_info_init(){
  affine_init.affine_k1_lb = gtk_label_new("密钥1:");
  affine_init.affine_k1_text = gtk_entry_new();
  affine_init.affine_k1_text_buffer = gtk_entry_get_buffer(GTK_ENTRY(affine_init.affine_k1_text));
  affine_init.affine_k2_lb = gtk_label_new("密钥2:");
  affine_init.affine_k2_text = gtk_entry_new();
  affine_init.affine_k2_text_buffer = gtk_entry_get_buffer(GTK_ENTRY(affine_init.affine_k2_text));
}

void ED_DES_info_init(){
  des_init.DES_k_lb = gtk_label_new("密钥:");
  des_init.DES_k_text = gtk_entry_new();
  des_init.DES_k_text_buffer = gtk_entry_get_buffer(GTK_ENTRY(des_init.DES_k_text));
}

void ED_SMA_infor_init(){
  sma_init.SMA_pow_lb = gtk_label_new("几次方:");
  sma_init.SMA_pow_text = gtk_entry_new();
  sma_init.SMA_pow_text_buffer = gtk_entry_get_buffer(GTK_ENTRY(sma_init.SMA_pow_text));
  sma_init.SMA_mod_lb = gtk_label_new("mod:");
  sma_init.SMA_mod_text = gtk_entry_new();
  sma_init.SMA_mod_text_buffer = gtk_entry_get_buffer(GTK_ENTRY(sma_init.SMA_mod_text));
}

void ED_RSA_info_init(){
  rsa_init.RSA_p_lb = gtk_label_new("p:");
  rsa_init.RSA_p_text = gtk_entry_new();
  rsa_init.RSA_p_text_buffer = gtk_entry_get_buffer(GTK_ENTRY(rsa_init.RSA_p_text));
  rsa_init.RSA_q_lb = gtk_label_new("q:");
  rsa_init.RSA_q_text = gtk_entry_new();
  rsa_init.RSA_q_text_buffer = gtk_entry_get_buffer(GTK_ENTRY(rsa_init.RSA_q_text));
  rsa_init.RSA_e_lb = gtk_label_new("公钥e:");
  rsa_init.RSA_e_text = gtk_entry_new();
  rsa_init.RSA_e_text_buffer = gtk_entry_get_buffer(GTK_ENTRY(rsa_init.RSA_e_text));
}

void ED_info_box_add(){
  int tmp = gtk_combo_box_get_active(GTK_COMBO_BOX(w_ctl.choose_cbb));
  w_ctl.input_info_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  printf("%d\n", tmp);
  switch(tmp){
    case 0:
      ED_sub_info_init();
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), sub_init.sub_k_lb);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), sub_init.sub_k_text);
      break;
    case 1:
      ED_affine_info_init();
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), affine_init.affine_k1_lb);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), affine_init.affine_k1_text);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), affine_init.affine_k2_lb);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), affine_init.affine_k2_text);
      break;
    case 2:
      ED_DES_info_init();
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), des_init.DES_k_lb);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), des_init.DES_k_text);
      break;
    case 3:
      ED_SMA_infor_init();
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), sma_init.SMA_pow_lb);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), sma_init.SMA_pow_text);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), sma_init.SMA_mod_lb);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), sma_init.SMA_mod_text);
      break;
    case 4:
      ED_RSA_info_init();
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), rsa_init.RSA_p_lb);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), rsa_init.RSA_p_text);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), rsa_init.RSA_q_lb);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), rsa_init.RSA_q_text);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), rsa_init.RSA_e_lb);
      gtk_box_append(GTK_BOX(w_ctl.input_info_box), rsa_init.RSA_e_text);
      break;
    default:
      printf("功能尚未完成\n");
  }
}

void widget_init(){
  GtkTreeIter iter;
  GtkCellRenderer * renderer;
  w_ctl.body_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign (w_ctl.body_box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (w_ctl.body_box, GTK_ALIGN_CENTER);

  /*加密方式选择*/
  w_ctl.ED_choose_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

  w_ctl.ED_list_lb = gtk_label_new("加密方式选择");

  w_ctl.choose_cbb = gtk_combo_box_new();
  w_ctl.choose_list_store = gtk_list_store_new(1,G_TYPE_STRING);
  gtk_list_store_append(w_ctl.choose_list_store,&iter);
  gtk_list_store_set(w_ctl.choose_list_store, &iter, 0, "移位密码", -1);
  gtk_list_store_append(w_ctl.choose_list_store,&iter);
  gtk_list_store_set(w_ctl.choose_list_store,&iter,0, "仿射密码",-1);
  gtk_list_store_append(w_ctl.choose_list_store,&iter);
  gtk_list_store_set(w_ctl.choose_list_store,&iter,0, "DES",-1);
  gtk_list_store_append(w_ctl.choose_list_store,&iter);
  gtk_list_store_set(w_ctl.choose_list_store,&iter,0, "平方-乘法算法",-1);
  gtk_list_store_append(w_ctl.choose_list_store,&iter);
  gtk_list_store_set(w_ctl.choose_list_store,&iter,0, "RSA",-1);
  gtk_combo_box_set_model(GTK_COMBO_BOX(w_ctl.choose_cbb), GTK_TREE_MODEL(w_ctl.choose_list_store));
  renderer = gtk_cell_renderer_text_new();
  gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(w_ctl.choose_cbb),renderer,TRUE);
  gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(w_ctl.choose_cbb),renderer,"text",0,NULL);
  gtk_combo_box_set_active(GTK_COMBO_BOX(w_ctl.choose_cbb),0);

  w_ctl.ED_choose_lb = gtk_label_new("加/解密");

  w_ctl.ED_choose_cbb = gtk_combo_box_new();
  w_ctl.ED_choose_list_store = gtk_list_store_new(1, G_TYPE_STRING);
  gtk_list_store_append(w_ctl.ED_choose_list_store, &iter);
  gtk_list_store_set(w_ctl.ED_choose_list_store, &iter, 0, "加密", -1);
  gtk_list_store_append(w_ctl.ED_choose_list_store, &iter);
  gtk_list_store_set(w_ctl.ED_choose_list_store, &iter, 0, "解密", -1);
  gtk_combo_box_set_model(GTK_COMBO_BOX(w_ctl.ED_choose_cbb), GTK_TREE_MODEL(w_ctl.ED_choose_list_store));
  renderer = gtk_cell_renderer_text_new();
  gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(w_ctl.ED_choose_cbb), renderer, TRUE);
  gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(w_ctl.ED_choose_cbb),renderer,"text",0,NULL);
  gtk_combo_box_set_active(GTK_COMBO_BOX(w_ctl.ED_choose_cbb),0);

  //布局
  gtk_box_append(GTK_BOX(w_ctl.ED_choose_box), w_ctl.ED_list_lb);
  gtk_box_append(GTK_BOX(w_ctl.ED_choose_box), w_ctl.choose_cbb);
  gtk_box_append(GTK_BOX(w_ctl.ED_choose_box), w_ctl.ED_choose_lb);
  gtk_box_append(GTK_BOX(w_ctl.ED_choose_box), w_ctl.ED_choose_cbb);

  /*信息输入框*/
  //总布局frame
  w_ctl.input_frame = gtk_frame_new("信息输入");
  
  //总布局box
  w_ctl.input_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  
  //信息输入框text
  w_ctl.input_text = gtk_text_view_new();
  gtk_widget_set_hexpand(w_ctl.input_text, 1);
  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(w_ctl.input_text),GTK_WRAP_CHAR);
  w_ctl.input_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w_ctl.input_text));

  w_ctl.input_scrolled_tx = gtk_scrolled_window_new();
  gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(w_ctl.input_scrolled_tx),w_ctl.input_text);

  //所需信息box
  gtk_box_append(GTK_BOX(w_ctl.input_box), w_ctl.input_scrolled_tx);
  gtk_frame_set_child(GTK_FRAME(w_ctl.input_frame), w_ctl.input_box);

  /*执行按钮*/
  w_ctl.ED_btn = gtk_button_new_with_label("加密");

  /*信息输出框*/
  w_ctl.output_frame = gtk_frame_new("信息输出");
  w_ctl.output_text = gtk_text_view_new();
  gtk_widget_set_hexpand(w_ctl.output_text, 1);
  gtk_widget_set_sensitive(w_ctl.output_text, 1);
  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(w_ctl.output_text),GTK_WRAP_CHAR);
  w_ctl.output_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w_ctl.output_text));

  w_ctl.output_scrolled_tx = gtk_scrolled_window_new();
  gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(w_ctl.output_scrolled_tx),w_ctl.output_text);

  gtk_frame_set_child(GTK_FRAME(w_ctl.output_frame), w_ctl.output_scrolled_tx);
  
  /*总布局*/
  gtk_box_append(GTK_BOX(w_ctl.body_box), w_ctl.ED_choose_box);
  gtk_box_append(GTK_BOX(w_ctl.body_box), w_ctl.input_frame);
  gtk_box_append(GTK_BOX(w_ctl.body_box), w_ctl.ED_btn);
  gtk_box_append(GTK_BOX(w_ctl.body_box), w_ctl.output_frame);
}

void input_frame_change(){
  printf("input_frame_change\n");
  gtk_box_remove(GTK_BOX(w_ctl.input_box), w_ctl.input_info_box);
  ED_info_box_add();
  gtk_box_append(GTK_BOX(w_ctl.input_box), w_ctl.input_info_box);
}

void ED_cbb_change(){
  printf("ED_cbb_change\n");
  if(gtk_combo_box_get_active(GTK_COMBO_BOX(w_ctl.ED_choose_cbb)) == 0)
    gtk_button_set_label(GTK_BUTTON(w_ctl.ED_btn), "加密");
  else
    gtk_button_set_label(GTK_BUTTON(w_ctl.ED_btn), "解密");
}

char ** get_keys(){
  char ** key;
  int ED_active = gtk_combo_box_get_active(GTK_COMBO_BOX(w_ctl.choose_cbb));
  switch(ED_active){
    case 0:
      key = (char **)malloc(sizeof(char *));
      *key = (char *)gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(sub_init.sub_k_text_buffer));
      break;
    case 1:
      key = (char **)malloc(sizeof(char *) * 2);
      *key = (char *)gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(affine_init.affine_k1_text_buffer));
      *(key + 1) = (char *)gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(affine_init.affine_k2_text_buffer));
      break;
    case 2:
      key = (char **)malloc(sizeof(char *));
      *key = (char *) gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(des_init.DES_k_text_buffer));
      break;
    case 3:
      key = (char **) malloc(sizeof(char *));
      *key = (char *)gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(sma_init.SMA_pow_text_buffer));
      *(key + 1) = (char *)gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(sma_init.SMA_mod_text_buffer));
      break;
    case 4:
      key = (char **) malloc(sizeof(char *));
      *key = (char *)gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(rsa_init.RSA_p_text_buffer));
      *(key + 1) = (char *)gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(rsa_init.RSA_q_text_buffer));
      *(key + 2) = (char *)gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(rsa_init.RSA_e_text_buffer));
      break;
    defualt:
      key = (char **)malloc(sizeof(char *));
      *key = "0";
      printf("功能尚未完善1\n");
  }
  
  return key;
}

void ED_btn_signal(){
  printf("ED_btn_signal\n");
  //加密所需信息
  GtkTextIter iter_end;
  GtkTextIter iter_start;
  int ED_active = gtk_combo_box_get_active(GTK_COMBO_BOX(w_ctl.choose_cbb));
  int E_OR_D = gtk_combo_box_get_active(GTK_COMBO_BOX(w_ctl.ED_choose_cbb));
  char * massage_input;
  char * massage_output;
  char ** key;

  key = get_keys();
  
  gtk_text_buffer_get_end_iter(w_ctl.input_buffer,&iter_end);
  gtk_text_buffer_get_start_iter(w_ctl.input_buffer,&iter_start);
  massage_input = gtk_text_buffer_get_text(w_ctl.input_buffer,&iter_start,&iter_end,TRUE);
  massage_output = massage_ED(ED_active, E_OR_D, massage_input, key);
  gtk_text_buffer_set_text(GTK_TEXT_BUFFER(w_ctl.output_buffer), massage_output, strlen(massage_output));
}

void ED_signal_init(){
  g_signal_connect(w_ctl.choose_cbb, "changed", G_CALLBACK(input_frame_change), NULL);
  g_signal_connect(w_ctl.ED_choose_cbb, "changed", G_CALLBACK(ED_cbb_change), NULL);
  g_signal_connect(w_ctl.ED_btn, "clicked", G_CALLBACK(ED_btn_signal), NULL);
}

/**
 * @brief 
 * 
 * @param app 
 * @param user_data 
 */
static void activate (GtkApplication* app, gpointer user_data){
  GtkWidget *window;

  /*窗口*/
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 0, 0);
  
  //控件布局初始化
  widget_init();  //整体布局初始化
  ED_info_box_add();
  gtk_box_append(GTK_BOX(w_ctl.input_box), w_ctl.input_info_box);
  //事件初始化
  ED_signal_init();

  gtk_window_set_child (GTK_WINDOW (window), w_ctl.body_box);

  gtk_widget_show (window);
}

int gtk_main(int argc, char * argv[]){
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_REPLACE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}