require_relative 'spec_helper'

RSpec.describe Euler_11 do
  let(:example) {Euler_11.new("./input/euler_11_test_input.txt")}

  describe "#grid_search" do
    it "finds the greatest product 4 in a row in any direction" do
      expect(example.grid_search).to eq(64)
    end
  end
end
