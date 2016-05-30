Rails.application.routes.draw do
  devise_for :users
  resources :clientes
  resources :ambientes

  root 'static_pages#home'

  get 'new'           =>  'ambientes#new'
  get 'ambientes'     =>  'ambientes#index'
end
