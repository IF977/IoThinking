class WelcomeController < ApplicationController
  before_filter :set_menu
  
  def set_menu
    @M_home = "active"
  end
  
  def index
    
  end
end
