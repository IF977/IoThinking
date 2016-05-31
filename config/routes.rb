Rails.application.routes.draw do
  devise_for :users
  resources :clientes
  resources :ambientes

<<<<<<< HEAD
  # You can have the root of your site routed with "root"
  
  root 'welcome#index'
  
  get '/menu_index' => 'welcome#menu_index'
  get '/new' => 'ambientes#new'
  get '/ambientes/index' => 'ambientes#index'
  
  # Example of regular route:
  #   get 'products/:id' => 'catalog#view'
=======
  root 'static_pages#home'
>>>>>>> d8d82aafc431a1776c5cd7e3ae12d875249984af

  get     'new'           =>  'ambientes#new'
  get     'ambientes'     =>  'ambientes#index'
  get     'sobre'         =>  'static_pages#sobre'
  get     'contato'       =>  'static_pages#contato'
  get     'tutorial'      =>  'static_pages#tutorial'
  get     'enviar_senha'  =>  'users#password#new'
  delete  'logout'        =>  'clientes#destroy'
end
