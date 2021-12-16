#include <gtk/gtk.h>




void
on_button1_administration_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_gererlescapteurs_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_reclamation_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5_gererlestocks_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_gererlesmenus_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_arreter_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_dali_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_notercervice_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_noter_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_plusreclame_reclam_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherche_reclam_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_reclam_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_reclam_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_reclam_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_reclam_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_add_reclam_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_afficher_reclam_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_afficher_reclam_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherche1_reclam_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_recherche_reclam_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_recherche2_reclame_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_plusreclame_reclam_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_plusreclame_reclam_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_robo_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_note_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_reclamation_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_noterservice_reclamation_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajoutajout_capt_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_ajoutcapt_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ajoutcapt2_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_retour_ajoutcapt_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_interfacecapt_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouter_interfacecapt_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_interfacecapt_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_interfacecapt_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherche_interfacecapt_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_interfacecapt_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_captdeff_interfacecapt_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_ouisupp_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ok_ahmedsupp_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ok_modifiercapt_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_modifiercapt_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_captdef_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_afficher_captdef_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_captdef_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_nouvprod_stock_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_prodrept_stock_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_fiche_stock_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_suppprod_stock_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_rechercheprod_stock_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_fichestock_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modif_fichestock_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_fichestock_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_ok_modifstock_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourmodif_stock_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_recherchestock_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_recherchestock_clicked       (GtkButton       *button,
                                        gpointer         user_data);
