class WelcomeController < ApplicationController
  def index
    if user_signed_in?
      redirect_to "/menu_index"
    end
  end
end
