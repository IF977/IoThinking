Rails.application.routes.draw do
  devise_for :users
  resources :clientes
  resources :ambientes

  # You can have the root of your site routed with "root"
  
  root 'welcome#index'
  
  get '/menu_index' => 'welcome#menu_index'
  get '/new' => 'ambientes#new'
  get '/ambientes/index' => 'ambientes#index'
  
  # Example of regular route:
  #   get 'products/:id' => 'catalog#view'

  get     'new'           =>  'ambientes#new'
  get     'ambientes'     =>  'ambientes#index'
  get     'enviar_senha'  =>  'users#password#new'
  delete  'logout'        =>  'clientes#destroy'
end
