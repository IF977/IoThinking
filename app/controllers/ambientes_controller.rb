class AmbientesController < ApplicationController
  before_action :set_ambiente, only: [:show, :edit, :update, :destroy]

  # GET /ambientes
  # GET /ambientes.json
  def index
    @ambientes = Ambiente.all
  end

  # GET /ambientes/1
  # GET /ambientes/1.json
  def show
  end

  # GET /ambientes/new
  def new
    @ambiente = Ambiente.new
  end

  # GET /ambientes/1/edit
  def edit
  end

  # POST /ambientes
  # POST /ambientes.json
  def create
    @ambiente = Ambiente.new(ambiente_params)

    respond_to do |format|
      if @ambiente.save
        format.html { redirect_to @ambiente, notice: 'Ambiente was successfully created.' }
        format.json { render :show, status: :created, location: @ambiente }
      else
        format.html { render :new }
        format.json { render json: @ambiente.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /ambientes/1
  # PATCH/PUT /ambientes/1.json
  def update
    respond_to do |format|
      if @ambiente.update(ambiente_params)
        format.html { redirect_to @ambiente, notice: 'Ambiente was successfully updated.' }
        format.json { render :show, status: :ok, location: @ambiente }
      else
        format.html { render :edit }
        format.json { render json: @ambiente.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /ambientes/1
  # DELETE /ambientes/1.json
  def destroy
    @ambiente.destroy
    respond_to do |format|
      format.html { redirect_to ambientes_url, notice: 'Ambiente was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_ambiente
      @ambiente = Ambiente.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def ambiente_params
      params.require(:ambiente).permit(:name)
    end
end
