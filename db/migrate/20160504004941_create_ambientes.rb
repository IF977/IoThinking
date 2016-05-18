class CreateAmbientes < ActiveRecord::Migration
  def change
    create_table :ambientes do |t|
      t.string :name

      t.timestamps null: false
    end
  end
end
