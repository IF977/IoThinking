Rails.application.routes.draw do
  devise_for :users
  resources :clientes
  resources :ambientes

  root 'static_pages#home'

  get     'new'           =>  'ambientes#new'
  get     'ambientes'     =>  'ambientes#index'
  get     'sobre'         =>  'static_pages#sobre'
  get     'contato'       =>  'static_pages#contato'
  get     'tutorial'      =>  'static_pages#tutorial'
  get     'enviar_senha'  =>  'users#password#new'
  delete  'logout'        =>  'clientes#destroy'
end
